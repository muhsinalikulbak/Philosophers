/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 02:36:50 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/21 20:45:10 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*supervisor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)(arg);

	
}

static bool check_death(t_philo *philo)
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
			return (true);
		}
		i++;
	}
	return (false);
}

static bool check_meals(t_philo *philo)
{
    
}
