/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:36:50 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/22 00:30:31 by muhsin           ###   ########.fr       */
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
	params = philo->params;
	curr_time = get_current_time();
	pthread_mutex_lock(philo->meal_mutex);
	last_time = philo->last_meal_time;
	pthread_mutex_unlock(philo->meal_mutex);
	while (i < philo->params->philo_count)
	{
		if (curr_time - last_time > params->time_to_die)
		{
			print_status(philo, curr_time, "is died");
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
	int	meal_conut;

	if (philo->params->must_eat == -1)
		return (false);
	i = 0;
	meal_conut = 0;
	while (i < philo->params->philo_count)
	{
		if (philo[i].meals_eaten >= philo->params->must_eat)
			meal_conut++;
		i++;
	}
	if (meal_conut == philo->params->must_eat)
		return (true);
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
		accurate_sleep(1000);
	}
	return (NULL);
}
