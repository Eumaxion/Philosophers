/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:38:04 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/25 19:38:48 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulation_finished(t_data *data)
{
	int	end;

	pthread_mutex_lock(&data->lock_mutex);
	end = data->simulation_end;
	pthread_mutex_unlock(&data->lock_mutex);
	return (end);
}

int	check_death(t_data *data, int i)
{
	t_philo	*p;
	int		current_time;

	p = &data->philos[i];
	current_time = get_time() - p->data->start_time;
	pthread_mutex_lock(&data->lock_mutex);
	if (get_time() - p->last_meal > data->time_to_die)
	{
		data->simulation_end = 1;
		pthread_mutex_unlock(&data->lock_mutex);
		pthread_mutex_lock(&data->print_mutex);
		ft_putnbr_fd(current_time, 1);
		write(1, " ", 1);
		ft_putnbr_fd(p->id, 1);
		write(1, " ", 1);
		ft_putstr_fd("died\n", 1);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->lock_mutex);
	return (0);
}

int	check_meals(t_data *data)
{
	int	i;

	if (data->must_eat <= 0)
		return (0);
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat)
			return (0);
		i++;
	}
	pthread_mutex_lock(&data->lock_mutex);
	data->simulation_end = 1;
	pthread_mutex_unlock(&data->lock_mutex);
	return (1);
}

void	*monitor(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	while (!simulation_finished(data))
	{
		i = 0;
		while (i < data->num_philos && !simulation_finished(data))
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
