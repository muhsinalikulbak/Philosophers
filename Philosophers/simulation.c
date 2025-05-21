/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 00:42:37 by muhsin            #+#    #+#             */
/*   Updated: 2025/05/21 11:54:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	is_sim_ended(t_philo *philo)
{
	bool	status;
	
	pthread_mutex_lock(philo->params->death_mutex);
	status = philo->params->sim_end;
	pthread_mutex_unlock(philo->params->death_mutex);
	return (status);
}

static void	*philosopher_routine(void *arg)
{
	t_philo *philo = (t_philo*)(arg);

	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->meal_mutex);
	if (philo->params->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, get_current_time(), "has taken a fork");
		accurate_sleep(philo->params->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	while (is_sim_ended(philo))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep(philo);
		thinking(philo);
	}
	return (NULL);
}

static bool	create_thread(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]) != 0)
		{
			error_manage(STDERR, philos->params, philos);
			return (false);
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


bool start_simulation(t_philo *philos)
{
	create_thread(philos);
	wait_thread(philos);

}
