/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:59:12 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/08 02:08:35 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	kill_philosopherse(t_philo *philos, pid_t death_pid)
{
	int	i;

	i = 0;
	while (i < philos->params->philo_count)
	{
		if (philos[i].pid != death_pid)
			kill(philos[i].pid, SIGKILL);
		i++;
	}
	while (wait(NULL) > 0)
		;
}
