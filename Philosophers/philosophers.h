/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:46:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/11 19:44:25 by mkulbak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

typedef struct s_forks
{
	pthread_mutex_t mutex;
	int mutex_id;
}               t_forks;

typedef struct s_params
{
	int	philo_count;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int must_eat;
}				t_params;

typedef struct s_philosopher
{
	pthread_t		thread;
	pthread_mutex_t meal_mutex;
	t_forks			*left_fork;
	t_forks			*right_fork;
	t_params		*params;
	int				id;
	int				last_meal_time;
	int				meals_eaten;
}               t_philosophers;


bool	argv_checker(int argc, char **argv);
long	get_current_time();

#endif