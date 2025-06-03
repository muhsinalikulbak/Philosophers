/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:56:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/03 12:20:09 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_status(t_philo *philo, long event_time, char *status)
{
	bool	sim_end;
	long	start_time;

	start_time = philo->params->start_time;
	pthread_mutex_lock(philo->params->death_mutex);
	sim_end = philo->params->sim_end;
	pthread_mutex_unlock(philo->params->death_mutex);
	pthread_mutex_lock(philo->params->print_mutex);
	if (sim_end)
		printf("%ld %d %s\n", event_time - start_time, philo->id, status);
	pthread_mutex_unlock(philo->params->print_mutex);
}

void	accurate_sleep(int ms_time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < ms_time)
		usleep(50);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*concat;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concat = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!concat)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
	{
		concat[len1] = s1[len1];
		len1++;
	}
	while (s2[len2])
	{
		concat[len1 + len2] = s2[len2];
		len2++;
	}
	concat[len1 + len2] = '\0';
	return (concat);
}
