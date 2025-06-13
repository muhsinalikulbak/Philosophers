/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:59:12 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 21:27:38 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	destroy_semafor(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_count)
	{
		sem_unlink(params->meal_names[i]);
		i++;
	}
	sem_unlink("/print");
	sem_unlink("/death");
	sem_unlink("/forks");
}

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
