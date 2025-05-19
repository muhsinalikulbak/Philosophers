/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:49:18 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/19 03:24:57 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	print_status(philo, get_current_time(), "is eating");
}

void	sleep(t_philo *philo)
{
	accurate_sleep(philo->params->time_to_sleep);
	print_status(philo, get_current_time(), "is sleeping");
}

void	thinking(t_philo *philo)
{
	print_status(philo, get_current_time(), "is thinking");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
