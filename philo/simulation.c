#include "philo.h"

/* int	handle_threads(t_data *data)
{
	pthread_t	*ids;
	t_philo		*philos;
	pthread_t	mon_id;

	ids = malloc(sizeof(pthread_t) * data->nr_philos);
	if (!ids)
		return (-1);
	philos = malloc(sizeof(t_philo) * data->nr_philos);
	if (!philos)
		return (-1);
	if (create_mutexes(data, philos) != 0)
		return (-2);
	if (create_threads(data, philos, ids, &mon_id) != 0)
		return (-2);
	join_threads(data, ids, &mon_id);
	destroy_mutexes(data, philos);
	free(ids);
	free(philos);
	free(data->forks);
	return (0);
} */

static void	think(t_philo *p)
{
	print_status(p, "is thinking");
}

static void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->death_mutex);
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->data->death_mutex);

	print_status(p, "is eating");

	smart_sleep(p->data->time_to_eat);

	p->meals_eaten++;
}

static void	sleep_philo(t_philo *p)
{
	print_status(p, "is sleeping");
	smart_sleep(p->data->time_to_sleep);
}

void *philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!simulation_finished(philo->data))
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
	}
	return NULL;
}