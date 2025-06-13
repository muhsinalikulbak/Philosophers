/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:55:09 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/13 13:57:27 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# define EINVAL 10
# define STDERR 11

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

typedef struct s_params
{
	sem_t	*print_sem;
	sem_t	*death_sem;
	sem_t	*forks;
	char	**meal_names;
	long	start_time;
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
}				t_params;

typedef struct s_philo
{
	pthread_t	monitor;
	sem_t		*meal_sem;
	t_params	*params;
	pid_t		pid;
	long		last_meal_time;
	int			id;
	int			meals_eaten;
	bool		is_alive;
}			t_philo;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char	*s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
char	**create_sem_names(int philo_count, char *sem_name);
char	**free_all(char **double_str);
long	ft_atol(const char *str);
long	get_current_time(void);
int		ft_atoi(const char *str);
bool	ft_isdigit(int c);
bool	is_sim_ended(t_philo *philo);
void	print_status(t_philo *philo, long event_time, char *status);
void	accurate_sleep(int ms_time);
void	free_resources(t_params *params, t_philo *philos);
void	argv_checker(int argc, char **argv);
void	error_manage(int error_code, t_params *param, t_philo *phi);
void	initializer(t_params *params, t_philo **_philos, int argc, char **argv);
void	start_simulation(t_params *params, t_philo *philos);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	thinking(t_philo *philo);
void	put_forks(t_philo *philo);
void	ate_enough(t_philo *philo);
void	kill_philosophers(t_philo *philos, pid_t death_pid);
#endif
