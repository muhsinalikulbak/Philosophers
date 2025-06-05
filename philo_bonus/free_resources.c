/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:13:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/06 00:48:29 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	free_meals(t_philo *philos, char **names, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		if (philos->meal_sem != NULL)
		{
			sem_close(philos->meal_sem);
			sem_unlink(names[i]);
		}
		i++;
	}
	
}

void	free_forks(sem_t **forks, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->philo_count)
	{
		if (forks[i] != SEM_FAILED)
		{
			sem_close(forks[i]);
			sem_unlink(params->fork_names[i]);
		}
		i++;
	}
	free(forks);
	forks = NULL;
}

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	result = NULL;
	return (NULL);
}

void	free_resources(t_params *params, t_philo *philos)
{
	if (params != NULL)
	{
		if (params->print_sem != SEM_FAILED)
		{
			sem_close(params->print_sem);
			sem_unlink("/print");
		}
		if (params->death_sem != SEM_FAILED)
		{
			sem_close(params->print_sem);
			sem_unlink("/death");
		}
		free_forks(params->forks, params->fork_names);
		free_meals(philos, params->meal_names, params->philo_count);
	}
}

