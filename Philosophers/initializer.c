/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:32:45 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 20:53:11 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// sim_end ve sim_start olucak mı olucaksa neden gerek var

static bool	init_params(t_params *params, int argc, char **argv)
{
	params->philo_count = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (params->print_mutex == NULL)
		return (false);
	pthread_mutex_init(params->print_mutex, NULL);
	if (argc == 6)
		params->must_eat = ft_atoi(argv[5]);
	else
		params->must_eat = -1;
	params->sim_end = false;
}

static bool	init_philo(
	t_philo *philos, t_params *params, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < params->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].params = params;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % params->philo_count];
		philos[i].meal_mutex = malloc(sizeof(pthread_mutex_t));
		if (philos[i].meal_mutex == NULL)
			return (false);
		pthread_mutex_init(philos[i].meal_mutex, NULL);
		i++;
	}
}

static pthread_mutex_t	*init_mutex(int philo_count)
{
	pthread_mutex_t	*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	if (forks == NULL)
		return (NULL);
	while (i < philo_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

bool	initializer(t_params *params, t_philo *philos, int argc, char **argv)
{
	pthread_mutex_t *forks;

	if (!init_params(params, argc, argv))
		return (error_manage(EMALLOC, NULL, philos, false));
	forks = init_mutex(params->philo_count);
	if (forks == NULL)
		return (error_manage(EMALLOC, params, philos, false));
	if (!init_philo(philos, params, forks))
		return (error_manage(EMALLOC, params, philos, true));
	
}
