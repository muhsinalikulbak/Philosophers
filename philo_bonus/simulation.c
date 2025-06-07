/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 13:32:20 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/07 21:41:05 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	philosopher_routine(t_philo philo)
{
	
	take_forks(philo);
	eat(philo);
	put_forks(philo);
	sleep_philo(philo);
	thinking(philo);
	return (NULL);
}

bool	start_simulation(t_params *params, t_philo *philos)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < params->philo_count)
	{
		pid = fork();
		if (pid == 0)
		{
			philosopher_routine(philos[i]);
			exit(0);
		}
		philos[i].pid = pid;
		i++;
	}
	// WAİTPİD İle ölüm kontrolü ve sigkill ile bitirme
	return (true);
}

// Her process'i kontrol eden bir thread olsun
// Bu thread ölümü kontrol edecek.
