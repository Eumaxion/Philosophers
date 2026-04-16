#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

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
void	init_data(t_data *data, int ac, char **av);
void	init_philos(t_data *data);
long	get_time(void);
void	*philo_routine(void *arg);
void	*monitor(void *arg);
int		simulation_finished(t_data *data);
void	put_forks(t_philo *p);
void	take_forks(t_philo *p);
long	ft_atol(const char *nptr);
int		ft_atoi(const char *nptr);
void	print_status(t_philo *p, char *msg);
void	cleanup(t_data *data);

#endif
