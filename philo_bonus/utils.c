/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:56:27 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 21:27:45 by mkulbak          ###   ########.fr       */
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
	long	start_time;

	start_time = philo->params->start_time;
	sem_wait(philo->params->print_sem);
	sem_wait(philo->meal_sem);
	if (philo->is_alive)
		printf("%ld %d %s\n", event_time - start_time, philo->id, status);
	else
	{
		printf("%ld %d %s\n", event_time - start_time, philo->id, status);
		sem_post(philo->meal_sem);
		return ;
	}
	sem_post(philo->meal_sem);
	sem_post(philo->params->print_sem);
}

void	accurate_sleep(int ms_time)
{
	long	start_time;

	start_time = get_current_time();
	while ((get_current_time() - start_time) < ms_time)
		usleep(100);
}

static char	*ft_strjoin(char const *s1, char const *s2)
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
	while (s1 != NULL && s1[len1])
	{
		concat[len1] = s1[len1];
		len1++;
	}
	while (s2 != NULL && s2[len2])
	{
		concat[len1 + len2] = s2[len2];
		len2++;
	}
	concat[len1 + len2] = '\0';
	return (concat);
}

char	**create_sem_names(int philo_count, char *sem_name)
{
	int		i;
	char	*temp;
	char	**names;

	names = (char **)ft_calloc(philo_count + 1, sizeof(char *));
	if (names == NULL)
		return (NULL);
	i = -1;
	while (++i < philo_count)
	{
		temp = ft_itoa(i + 1);
		names[i] = ft_strjoin(sem_name, temp);
		if (temp == NULL || names[i] == NULL)
		{
			free_all(names);
			if (temp != NULL)
				free(temp);
			return (NULL);
		}
		free(temp);
	}
	return (names);
}
