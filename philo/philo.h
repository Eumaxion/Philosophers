#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_data
{
	int				num_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	int				simulation_end;

	long			start_time;

	pthread_mutex_t *forks;
	pthread_mutex_t print_mutex;
	pthread_mutex_t death_mutex;
}	t_data;

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

int		main(int argc, char **argv);
void	print_status(t_philo *p, char *msg);
int		ft_atoi(const char *nptr);
void	take_forks(t_philo *p);
void	put_forks(t_philo *p);
void	*philo_routine(void *arg);
int		simulation_finished(t_data *data);
void	*monitor(void *arg);
void	init_args(t_data *table, int ac, char **av);

#endif


/* 
typedef struct s_table
{
	int				qty_philo;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	int				qty_eat;
	long			start_time;
	int				end_sim;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	lock_state;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				qty_eat;
	long			last_eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

--------------------------------------------------------------------------------------
typedef struct s_data
{
	int				nr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nr_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	stop_mutex;
	int				stop;
	int				meals_defined;	
	long			start_time;	
}				t_data;

typedef struct s_philo
{
	int				right_fork;
	int				left_fork;
	int				philo_id;
	pthread_mutex_t	meal_mutex;
	long			last_meal;
	int				ate;
	t_data			*data;

}				t_philo; 
*/