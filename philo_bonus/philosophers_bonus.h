/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:55:09 by muhsin            #+#    #+#             */
/*   Updated: 2025/06/05 20:29:58 by muhsin           ###   ########.fr       */
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

# define EINVAL 10
# define STDERR 10

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"

typedef struct s_params
{
	sem_t	*print_sem;
	sem_t	*death_sem;
	sem_t	**forks;
	long	start_time;
	int		philo_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	bool	sim_end;
}				t_params;

typedef struct s_philo
{
	sem_t		*meal_sem;
	sem_t		*left_fork;
	sem_t		*right_fork;
	t_params	*params;
	int			id;
	long		last_meal_time;
	int			meals_eaten;
}			t_philo;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char	*s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
long	ft_atol(const char *str);
long	get_current_time(void);
int		ft_atoi(const char *str);
int		error_manage(int error_code, t_params *param, t_philo *phi);
bool	ft_isdigit(int c);
bool	argv_checker(int argc, char **argv);
bool	initializer(t_params *params, t_philo **_philos, int argc, char **argv);
bool	start_simulation(t_philo *philos);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	thinking(t_philo *philo);
void	put_forks(t_philo *philo);
void	print_status(t_philo *philo, long event_time, char *status);
void	accurate_sleep(int ms_time);
void	*supervisor_routine(void *arg);
void	free_resources(t_params *params, t_philo *philos);
void	free_forks(sem_t **forks);
#endif
