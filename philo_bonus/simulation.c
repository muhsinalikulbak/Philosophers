/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:32:20 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 14:20:27 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

bool	is_sim_ended(t_philo *philo)
{
	bool	status;

	sem_wait(philo->meal_sem);
	status = philo->is_alive;
	sem_post(philo->meal_sem);
	return (status);
}

static void	*monitor(void *arg)
{
	t_philo	*philo;
	long	curr_time;
	int		time_to_die;
	long	las_meal_time;

	philo = (t_philo *)arg;
	time_to_die = philo->params->time_to_die;
	while (is_sim_ended(philo))
	{
		curr_time = get_current_time();
		sem_wait(philo->meal_sem);
		las_meal_time = philo->last_meal_time;
		sem_post(philo->meal_sem);
		if (curr_time - las_meal_time > time_to_die)
		{
			sem_wait(philo->params->death_sem);
			sem_wait(philo->meal_sem);
			philo->is_alive = false;
			sem_post(philo->meal_sem);
			print_status(philo, curr_time, "died");
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

static void	philosopher_routine(t_philo *philo)
{
	int			must_eat;

	must_eat = philo->params->must_eat;
	sem_wait(philo->meal_sem);
	philo->last_meal_time = get_current_time();
	sem_post(philo->meal_sem);
	pthread_create(&philo->monitor, NULL, monitor, philo);
	pthread_detach(philo->monitor);
	while (is_sim_ended(philo))
	{
		if (must_eat != -1 && philo->meals_eaten >= must_eat)
			ate_enough(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
		thinking(philo);
	}
	free_resources(philo->params, (philo - (philo->id - 1)));
	exit(EXIT_FAILURE);
}

static void	status_detector(t_philo *philos)
{
	int		status;
	int		meal_count;
	pid_t	death_pid;

	meal_count = 0;
	while (true)
	{
		death_pid = waitpid(-1, &status, WNOHANG);
		if (death_pid > 0)
		{
			if (WIFEXITED(status) && WEXITSTATUS(status) == 42)
			{
				if (++meal_count == philos->params->philo_count)
					return ;
			}
			else if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			{
				kill_philosophers(philos, death_pid);
				sem_post(philos->params->death_sem);
				sem_post(philos->params->print_sem);
				return ;
			}
		}
		usleep(1000);
	}
}

void	start_simulation(t_params *params, t_philo *philos)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < params->philo_count)
	{
		pid = fork();
		if (pid == 0)
		{
			philosopher_routine(&philos[i]);
			exit(EXIT_SUCCESS);
		}
		philos[i].pid = pid;
		i++;
	}
	status_detector(philos);
	while (wait(NULL) > 0)
		;
}
