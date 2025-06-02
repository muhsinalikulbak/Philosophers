/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:36:50 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/02 21:33:33 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_death(t_philo *philo)
{
	t_params	*params;
	long		curr_time;
	long		last_time;
	int			i;

	i = 0;
	curr_time = get_current_time();
	params = philo->params;
	while (i < philo->params->philo_count)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		last_time = philo[i].last_meal_time;
		pthread_mutex_unlock(philo[i].meal_mutex);
		if (curr_time - last_time > params->time_to_die)
		{
			print_status(&philo[i], curr_time, "died");
			pthread_mutex_lock(params->death_mutex);
			params->sim_end = false;
			pthread_mutex_unlock(params->death_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

static bool	check_meals(t_philo *philo)
{
	int	i;
	int	meal_count;
	int	meals_eaten;

	if (philo->params->must_eat == -1)
		return (false);
	i = -1;
	meal_count = 0;
	while (++i < philo->params->philo_count)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		meals_eaten = philo[i].meals_eaten;
		pthread_mutex_unlock(philo[i].meal_mutex);
		if (meals_eaten >= philo->params->must_eat)
			meal_count++;
	}
	if (meal_count == philo->params->philo_count)
	{
		pthread_mutex_lock(philo->params->death_mutex);
		philo->params->sim_end = false;
		pthread_mutex_unlock(philo->params->death_mutex);
		return (true);
	}
	return (false);
}

void	*supervisor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)(arg);
	while (true)
	{
		if (check_death(philo) || check_meals(philo))
			break ;
		accurate_sleep(1);
	}
	return (NULL);
}
