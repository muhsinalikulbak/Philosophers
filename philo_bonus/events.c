/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 02:49:18 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 21:27:15 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	take_forks(t_philo *philo)
{
	usleep(100);
	if (!is_sim_ended(philo))
		return ;
	sem_wait(philo->params->forks);
	print_status(philo, get_current_time(), "has taken a fork");
	sem_wait(philo->params->forks);
	print_status(philo, get_current_time(), "has taken a fork");
}

void	eat(t_philo *philo)
{
	usleep(100);
	if (!is_sim_ended(philo))
		return ;
	print_status(philo, get_current_time(), "is eating");
	accurate_sleep(philo->params->time_to_eat);
	sem_wait(philo->meal_sem);
	philo->last_meal_time = get_current_time();
	sem_post(philo->meal_sem);
	philo->meals_eaten++;
}

void	sleep_philo(t_philo *philo)
{
	usleep(100);
	if (!is_sim_ended(philo))
		return ;
	print_status(philo, get_current_time(), "is sleeping");
	accurate_sleep(philo->params->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	usleep(100);
	if (!is_sim_ended(philo))
		return ;
	print_status(philo, get_current_time(), "is thinking");
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->params->forks);
	sem_post(philo->params->forks);
}
