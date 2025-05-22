/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:46:00 by mkulbak           #+#    #+#             */
/*   Updated: 2025/05/22 17:20:28 by muhsin           ###   ########.fr       */
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

# define EINVAL 10
# define STDERR 10

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

typedef struct s_params
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*death_mutex;
	pthread_mutex_t	*forks;
	pthread_t		supervisor;
	long			start_time;
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
	long			last_meal_time;
	int				meals_eaten;
}			t_philo;

long	get_current_time(void);
bool	argv_checker(int argc, char **argv);
void	free_resources(t_params *params, t_philo *philos);
bool	initializer(t_params *params, t_philo **_philos, int argc, char **argv);
int		error_manage(int error_code, t_params *param, t_philo *phi);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	thinking(t_philo *philo);
void	put_forks(t_philo *philo);
void	print_status(t_philo *philo, long event_time, char *status);
void	accurate_sleep(int ms_time);
void	*supervisor_routine(void *arg);
bool	start_simulation(t_philo *philos);
#endif
