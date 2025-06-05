/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:13:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/05 18:12:11 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
		free_forks(params->forks);
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
	forks = NULL;
}
