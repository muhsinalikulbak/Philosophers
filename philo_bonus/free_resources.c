/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:13:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/05 13:47:46 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static	void	destroy_mutex(t_philo *philos, t_params *params)
{
	int	i;

	i = 0;
	if (params != NULL && philos != NULL)
	{
		while (i < params->philo_count && philos[i].meal_mutex != NULL)
		{
			pthread_mutex_destroy(philos[i].meal_mutex);
			free(philos[i].meal_mutex);
			i++;
		}
	}
	i = 0;
	if (params != NULL && params->forks != NULL)
	{
		while (i < params->philo_count)
		{
			pthread_mutex_destroy(&params->forks[i]);
			i++;
		}
	}
}

void	free_resources(t_params *params, t_philo *philos)
{
	if (params != NULL)
	{
		if (params->print_sem != SEM_FAILED)
		{
			sem_close(params->print_sem);
			sem_unlink(params->print_sem);
		}
		if (params->death_sem != SEM_FAILED)
		{
			sem_close(params->print_sem);
			sem_unlink(params->death_sem);
		}
	}
	if (philos != NULL)
	{

	}
	
}

void	free_forks(sem_t **forks)
{
	int	i;

	i = 0;
	while (forks[i])
	{
		if (forks[i] != SEM_FAILED)
		{
			sem_close(forks[i]);
			sem_unlink(forks[i]);
		}
		i++;
	}
	free(forks);
}
