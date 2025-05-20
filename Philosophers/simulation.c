/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:42:37 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/21 02:33:42 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo*)(arg);

	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->meal_mutex);
	while (is_sim_ended())
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep(philo);
		thinking(philo);
	}
	return (NULL);
}

static void	create_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]) != 0)
		{
			error_manage(STDERR, philos->params, philos);
			return ;
		}
		i++;
	}
}

static void	wait_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

static bool	is_sim_ended()
{
	
}

void	start_simulation(t_philo *philos)
{
	create_thread(philos);
	wait_thread(philos);

}