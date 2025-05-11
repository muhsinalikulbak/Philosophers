/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:46:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/12 02:44:29 by mkulbak          ###   ########.fr       */
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

typedef struct s_params
{
	pthread_mutex_t	*print_mutex;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			sim_end;
}				t_params;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_params		*params;
	int				id;
	int				last_meal_time;
	int				meals_eaten;
}			t_philo;

void	initializer(t_params *params, t_philo *philos, int argc, char **argv);
bool	argv_checker(int argc, char **argv);
long	get_current_time(void);
#endif
