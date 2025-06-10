/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:49:18 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/11 01:49:32 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	take_forks(t_philo *philo)
{
	sem_wait(philo->params->forks);
	sem_wait(philo->params->forks);	
}

void	eat(t_philo *philo)
{
	print_status(philo, get_current_time(), "is eating");
	accurate_sleep(philo->params->time_to_eat);
	sem_wait(philo->meal_sem);
	philo->last_meal_time = get_current_time();
	sem_post(philo->meal_sem);
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
	sem_post(philo->params->forks);
	sem_post(philo->params->forks);
}
