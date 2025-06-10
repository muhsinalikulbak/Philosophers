/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:32:45 by mkulbak           #+#    #+#             */
/*   Updated: 2025/06/11 01:51:39 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	set_default(t_params *params)
{
	params->forks = NULL;
	params->meal_names = NULL;
	params->death_sem = SEM_FAILED;
	params->print_sem = SEM_FAILED;
}

static bool	init_philo(t_philo *philos, t_params *params)
{
	int		i;

	i = 0;
	while (i < params->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].pid = -1;
		philos[i].meals_eaten = 0;
		philos[i].is_alive = true;
		philos[i].params = params;
		philos[i].meal_sem = sem_open(params->meal_names[i], O_CREAT, 0644, 1);
		if (philos[i].meal_sem == SEM_FAILED)
			return (false);
		i++;
	}
	return (true);
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
	params->forks = sem_open("/forks", O_CREAT, 0644, params->philo_count);
	if (params->death_sem == SEM_FAILED || params->print_sem == SEM_FAILED)
		return (false);
	params->meal_names = create_sem_names(params->philo_count, "/meal_");
	if (params->meal_names == NULL)
		return (false);
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
