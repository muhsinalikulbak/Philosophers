/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:32:45 by mkulbak           #+#    #+#             */
/*   Updated: 2025/06/07 21:42:49 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	set_default(t_params *params)
{
	params->forks = NULL;
    params->fork_names = NULL;
    params->meal_names = NULL;
    params->death_sem = SEM_FAILED;
    params->print_sem = SEM_FAILED;
}

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
		philos[i].pid = -1;
		philos[i].meals_eaten = 0;
		philos[i].is_alive = true;
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
	forks = (sem_t **)ft_calloc(philo_count, sizeof(sem_t *));
	if (forks == NULL)
		return (NULL);
	while (i < philo_count)
	{
		forks[i] = sem_open(params->fork_names[i], O_CREAT, 0644, 1);
		if (forks[i] == SEM_FAILED)
		{
			free_forks(forks, params);
			params->forks = NULL;
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
	params->fork_names = create_sem_names(params->philo_count, "/fork_");
	params->meal_names = create_sem_names(params->philo_count, "/meal_");
	if (params->fork_names == NULL || params->meal_names == NULL)
		return (false);
	params->forks = init_sem(params->philo_count, params);
	if (params->forks == NULL)
		return (false);
	params->sim_end = true;
	return (true);
}

void	initializer(t_params *params, t_philo **_philos, int argc, char **argv)
{
	t_philo	*philos;

	philos = (t_philo *)ft_calloc(ft_atoi(argv[1]), sizeof(t_philo));
	set_default(params);
	if (philos == NULL)
		error_manage(STDERR, NULL, NULL);
	if (!init_params(params, argc, argv))
		error_manage(STDERR, params, philos);
	if (!init_philo(philos, params))
		error_manage(STDERR, params, philos);
	params->start_time = get_current_time();
	*_philos = philos;
}
