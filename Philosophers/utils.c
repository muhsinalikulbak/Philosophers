/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:59:24 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/28 02:21:26 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_status(t_philo *philo, long event_time, char *status)
{
	long	start_time;

	start_time = philo->params->start_time;
	pthread_mutex_lock(philo->params->print_mutex);
	pthread_mutex_lock(philo->params->death_mutex);
	if (philo->params->sim_end)
		printf("%ld %d %s\n", event_time - start_time, philo->id, status);
	pthread_mutex_unlock(philo->params->death_mutex);
	pthread_mutex_unlock(philo->params->print_mutex);
}

void	accurate_sleep(int ms_time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < ms_time)
		usleep(100);
}
