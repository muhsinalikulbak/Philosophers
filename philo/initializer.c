/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:32:45 by mkulbak           #+#    #+#             */
/*   Updated: 2025/07/07 01:13:23 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

static bool	init_params(t_params *params, int argc, char **argv)
{
	params->philo_count = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	params->must_eat = -1;
	if (argc == 6)
		params->must_eat = ft_atoi(argv[5]);
	params->print_mutex = malloc(sizeof(pthread_mutex_t));
	params->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (params->print_mutex == NULL || params->death_mutex == NULL)
		return (false);
	if (pthread_mutex_init(params->print_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(params->death_mutex, NULL) != 0)
		return (false);
	params->forks = init_mutex(params->philo_count);
	if (params->forks == NULL)
		return (false);
	params->sim_end = true;
	return (true);
}

static bool	init_philo(
	t_philo *philos, t_params *params, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < params->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].params = params;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % params->philo_count];
		philos[i].meal_mutex = malloc(sizeof(pthread_mutex_t));
		if (philos[i].meal_mutex == NULL)
			return (false);
		if (pthread_mutex_init(philos[i].meal_mutex, NULL) != 0)
			return (false);
		pthread_mutex_lock(philos[i].meal_mutex);
		philos[i].last_meal_time = get_current_time();
		pthread_mutex_unlock(philos[i].meal_mutex);
		i++;
	}
	return (true);
}

int	initializer(t_params *params, t_philo **_philos, int argc, char **argv)
{
	t_philo			*philos;

	params->forks = NULL;
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (philos == NULL)
		return (error_manage(STDERR, NULL, NULL));
	if (!init_params(params, argc, argv))
		return (error_manage(STDERR, params, philos));
	if (!init_philo(philos, params, params->forks))
		return (error_manage(STDERR, params, philos));
	params->start_time = get_current_time();
	*_philos = philos;
	return (EXIT_SUCCESS);
}
