/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:28:54 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/13 00:15:21 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	void	destroy_mutex(t_philo *philos, t_params *params)
{
	int	i;

	i = 0;
	while (philos != NULL && i < params->philo_count && philos[i].meal_mutex != NULL)
	{
		pthread_mutex_destroy(philos[i].meal_mutex);
		free(philos[i].meal_mutex);
		i++;
	}
	i = 0;
	while (params != NULL && i < params->philo_count)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
}

void	free_resources(t_params *params, t_philo *philos, bool is_init_philo)
{
	if (params != NULL && params->print_mutex != NULL)
	{
		pthread_mutex_destroy(params->print_mutex);
		free(params->print_mutex);
	}
	if (philos != NULL)
	{
		if(is_init_philo)
			destroy_mutex(philos, params);
		free(philos);
	}
	if (params != NULL && params->forks != NULL)
		free(params->forks);
}
