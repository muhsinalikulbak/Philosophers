/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:32:45 by mkulbak           #+#    #+#             */
/*   Updated: 2025/06/05 23:45:50 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static bool	init_philo(t_philo *philos, t_params *params)
{
	int		i;
	sem_t	**forks;

	forks = params->forks;
	i = 0;
	while (i < params->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].params = params;
		philos[i].left_fork = forks[i];
		philos[i].right_fork = forks[(i + 1) % params->philo_count];
		philos[i].meal_sem = sem_open(params->meal_names[i], O_CREAT, 0644, 1);
		if (philos[i].meal_sem == SEM_FAILED)
			return (false);
		i++;
	}
	return (true);
}

static sem_t	**init_sem(int philo_count, t_params *params)
{
	sem_t	**forks;
	int		i;

	i = 0;
	forks = malloc(sizeof(sem_t *) * philo_count);
	if (forks == NULL)
		return (NULL);
	while (i < philo_count)
	{
		forks[i] = sem_open(params->fork_names[i], O_CREAT, 0644, 1);
		if (forks[i] == SEM_FAILED)
		{
			free_forks(forks, params);
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
	params->death_sem = sem_open("/death", O_CREAT, 0644, 1);
	params->print_sem = sem_open("/print", O_CREAT, 0644, 1);
	if (params->death_sem == SEM_FAILED || params->print_sem == SEM_FAILED)
		return (false);
	params->fork_names = create_sem_names(params->philo_count, "/fork : ");
	params->meal_names = create_sem_names(params->philo_count, "/meal : ");
	params->forks = init_sem(params->philo_count, params);
	if (params->forks == NULL)
		return (false);
	params->sim_end = true;
	params->start_time = get_current_time();
	return (true);
}

bool	initializer(t_params *params, t_philo **_philos, int argc, char **argv)
{
	t_philo	*philos;

	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (philos == NULL)
		return (error_manage(STDERR, NULL, NULL));
	if (!init_params(params, argc, argv))
		return (error_manage(STDERR, params, philos));
	if (!init_philo(philos, params))
		return (error_manage(STDERR, params, philos));
	*_philos = philos;
	return (true);
}
