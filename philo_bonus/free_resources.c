/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:13:32 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/11 01:47:58 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	free_meals(t_philo *philos, t_params *params)
{
	int		i;
	char	**names;

	names = params->meal_names;
	i = 0;
	if (philos != NULL && names != NULL)
	{
		while (i < params->philo_count)
		{
			if (philos[i].meal_sem != SEM_FAILED)
			{
				sem_close(philos[i].meal_sem);
				sem_unlink(params->meal_names[i]);
			}
			i++;
		}
	}
}

char	**free_all(char **double_str)
{
	int	i;

	i = 0;
	if (double_str != NULL)
	{
		while (double_str[i])
		{
			free(double_str[i]);
			i++;
		}
	}
	free(double_str);
	return (NULL);
}

void	free_resources(t_params *params, t_philo *philos)
{
	if (params->print_sem != SEM_FAILED)
	{
		sem_close(params->print_sem);
		sem_unlink("/print");
	}
	if (params->death_sem != SEM_FAILED)
	{
		sem_close(params->death_sem);
		sem_unlink("/death");
	}
	if (params->forks != SEM_FAILED)
	{
		sem_close(params->forks);
		sem_unlink("/forks");
	}
	if (philos != NULL)
	{
		free_meals(philos, params);
		free(philos);
	}
	free_all(params->meal_names);
}
