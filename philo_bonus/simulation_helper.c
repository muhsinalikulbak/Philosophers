/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:59:12 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 14:18:32 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ate_enough(t_philo *philo)
{
	t_philo	*base;

	base = philo - (philo->id - 1);
	sem_wait(philo->meal_sem);
	philo->is_alive = false;
	sem_post(philo->meal_sem);
	free_resources(philo->params, base);
	exit(42);
}

void	kill_philosophers(t_philo *philos, pid_t death_pid)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (philos[i].pid != death_pid)
			kill(philos[i].pid, SIGKILL);
		i++;
	}
}
