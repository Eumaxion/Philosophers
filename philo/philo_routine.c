#include "philo.h"

static void eat(t_philo *p)
{
	take_forks(p);
	pthread_mutex_lock(&p->data->death_mutex);
	p->last_meal = get_time();
	if (p->data->must_eat > 0)
		p->meals_eaten++;
	pthread_mutex_unlock(&p->data->death_mutex);
	print_status(p, "is eating");
	pthread_mutex_lock(&p->data->death_mutex);
	usleep(p->data->time_to_eat * 1000);
	pthread_mutex_unlock(&p->data->death_mutex);
	put_forks(p);
}

void *philo_routine(t_data *table, t_philo *p)
{
	if (p->data->num_philos == 1)
	{
		pthread_mutex_lock(p->left_fork);
		print_status(p, "has taken a fork");
		smart_sleep(p->data->time_to_die, p->data);
		return (NULL);
	}
	if (p->id % 2 == 0)
		usleep(1000);
	while (!simulation_finished(p->data))
	{
		eat(p);
		if (!simulation_finished(p->data))
			break;
		print_status(p, "is thinking");
		usleep(table->time_to_sleep * 1000);
		if (!simulation_finished(p->data))
			break;
		print_status(p, "is sleeping");
		if (table->num_philos % 2 && p->id % 2)
			usleep(1000);
	}
	return NULL;
}
