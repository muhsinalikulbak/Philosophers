/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:49:18 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/07 22:45:37 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		sem_wait(philo->right_fork);
		print_status(philo, get_current_time(), "has taken a fork");
		sem_wait(philo->left_fork);
		print_status(philo, get_current_time(), "has taken a fork");
	}
	else
	{
		sem_wait(philo->left_fork);
		print_status(philo, get_current_time(), "has taken a fork");
		sem_wait(philo->right_fork);
		print_status(philo, get_current_time(), "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	print_status(philo, get_current_time(), "is eating");
	accurate_sleep(philo->params->time_to_eat);
	philo->meals_eaten++;
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
	sem_post(philo->left_fork);
	sem_post(philo->right_fork);
}
