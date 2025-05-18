/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:42:37 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/19 02:18:47 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, long event_time, char *status)
{
	pthread_mutex_lock(philo->params->print_mutex);
	printf("%ld %d %s\n",event_time, philo->id, status);
	pthread_mutex_unlock(philo->params->print_mutex);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, get_current_time(), "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_current_time(), "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_current_time(), "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, get_current_time(), "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mutex);
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time(); 			
	pthread_mutex_unlock(philo->meal_mutex);
	
}

void	sleep(t_philo *philo)
{
	usleep(philo->params->time_to_sleep);
	print_status(philo, "")
}

void	thinking(t_philo *philo)
{
	
}

void	*philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo*)(arg);

	while (condition)
	{
		
	}
	
}