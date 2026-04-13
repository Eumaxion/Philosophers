#include "philo.h"

int simulation_finished(t_data *data)
{
	int finished;

	pthread_mutex_lock(&data->death_mutex);
	finished = data->simulation_end;
	pthread_mutex_unlock(&data->death_mutex);

	return finished;
}

void *monitor(void *arg)
{
	t_philo *philos = (t_philo *)arg;
	int i;

	while (1)
	{
		i = 0;
		while (i < philos[0].data->num_philos)
		{
			pthread_mutex_lock(&philos[i].data->death_mutex);

			if (get_time() - philos[i].last_meal > philos[i].data->time_to_die)
			{
				print_status(&philos[i], "died");
				philos[i].data->simulation_end = 1;

				pthread_mutex_unlock(&philos[i].data->death_mutex);
				return NULL;
			}

			pthread_mutex_unlock(&philos[i].data->death_mutex);
			i++;
		}
		usleep(1000);
	}
}
