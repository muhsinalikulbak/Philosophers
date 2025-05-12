/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:28:54 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 22:15:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_resources(t_params *params, t_philo *philos, bool is_init_philo)
{
	int	i;

	i = -1;
	if (params != NULL)
	{
		pthread_mutex_destroy(params->print_mutex);
		free(params->print_mutex);
	}
	if (philos != NULL && is_init_philo == false)
		free(philos);
	else if (philos != NULL && is_init_philo)
	{
		while (++i < params->philo_count)
		{
			if (philos[i].meal_mutex != NULL)
			{
				pthread_mutex_destroy(philos[i].meal_mutex);
				free(philos[i].meal_mutex);
			}
			pthread_mutex_destroy(philos[i].left_fork);
		}
		free(philos);
	}
	if (params->forks != NULL)
		free(params->forks);
}
