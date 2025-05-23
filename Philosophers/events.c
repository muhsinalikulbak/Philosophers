/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:49:18 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/23 18:05:22 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	int	must_eat;
	int	meals_eaten;

	pthread_mutex_lock(philo->meal_mutex);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(philo->meal_mutex);
	must_eat = philo->params->must_eat;
	if (must_eat != -1 && meals_eaten >= must_eat)
		return ;
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
	print_status(philo, get_current_time(), "is eating");
	pthread_mutex_lock(philo->meal_mutex);
	philo->meals_eaten++;
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->meal_mutex);
	accurate_sleep(philo->params->time_to_eat);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, get_current_time(), "is sleeping");
	accurate_sleep(philo->params->time_to_sleep);
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
