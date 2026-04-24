#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

# define ARGS_ERROR 1
# define THREAD_ERROR 2
# define MALLOC_ERROR 3
# define MUTEX_ERROR 5

typedef struct s_data t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	int				simulation_end;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
}	t_data;

int		main(int ac, char **av);
int		parse_args(int ac, char **av);
int		init_args(t_data *data, int ac, char **av);
long	get_time(void);
void	*philo_routine(void *philo);
void	*monitor(void *arg);
int		simulation_finished(t_data *data);
void	put_forks(t_philo *p);
void	take_forks(t_philo *p);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
void	print_status(t_philo *p, char *msg);
void	free_forks(t_data *data, int n);
void	cleanup(t_data *data);

#endif
