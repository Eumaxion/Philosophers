#include "philo.h"

int	simulation_finished(t_data *data)
{
	int end;

	pthread_mutex_lock(&data->death_mutex);
	end = data->simulation_end;
	pthread_mutex_unlock(&data->death_mutex);
	return (end);
}

int	check_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->death_mutex);
	if (get_time() - data->philos[i].last_meal > data->time_to_die)
	{
		printf("%ld %d died\n", get_time() - data->start_time,
			data->philos[i].id);
		data->simulation_end = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->death_mutex);
	return (0);
}

int	check_meals(t_data *data)
{
	int i;

	if (data->must_eat <= 0)
		return (0);
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&data->death_mutex);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->death_mutex);
	return (1);
}

void	*monitor(void *arg)
{
	t_data *data;
	int i;

	data = (t_data *)arg;
	while (!simulation_finished(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (check_death(data, i))
				return (NULL);
			i++;
		}
		if (check_meals(data))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}