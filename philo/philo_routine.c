#include "philo.h"

void	smart_sleep(long time, t_data *data)
{
	long start;

	start = get_time();
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->simulation_end)
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		if (get_time() - start >= time)
			break ;
		usleep(50);
	}
}

static void eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_mutex);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->data->death_mutex);
	print_status(p, "is eating");
	pthread_mutex_lock(&p->data->death_mutex);
	smart_sleep(p->data->time_to_eat, p->data);
	pthread_mutex_unlock(&p->data->death_mutex);
	p->meals_eaten++;
}

static void sleep_philo(t_philo *p)
{
	print_status(p, "is sleeping");
	smart_sleep(p->data->time_to_sleep, p->data);
}

static void think(t_philo *p)
{
	print_status(p, "is thinking");
	if (p->data->num_philos % 2 != 0)
		usleep(500);
}

void *philo_routine(void *arg)
{
	t_philo *p;

	p = (t_philo *)arg;
	if (p->data->num_philos == 1)
	{
		pthread_mutex_lock(p->left_fork);
		print_status(p, "has taken a fork");
		smart_sleep(p->data->time_to_die, p->data);
		return (NULL);
	}
	if (p->id % 2 == 0)
		usleep(2000);
	while (!simulation_finished(p->data))
	{
		think(p);
		take_forks(p);
		eat(p);
		put_forks(p);
		sleep_philo(p);
	}
	return NULL;
}