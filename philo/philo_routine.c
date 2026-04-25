/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 19:39:39 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/25 19:39:40 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->lock_mutex);
	free(data->forks);
	free(data->philos);
}

void	smart_sleep(long time, t_data *data)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (simulation_finished(data))
			break ;
		usleep(100);
	}
}

static void	eat(t_philo *p)
{
	take_forks(p);
	pthread_mutex_lock(&p->data->lock_mutex);
	p->last_meal = get_time();
	if (p->data->must_eat > 0)
		p->meals_eaten++;
	pthread_mutex_unlock(&p->data->lock_mutex);
	print_status(p, "is eating\n");
	smart_sleep(p->data->time_to_eat, p->data);
	put_forks(p);
}

void	*philo_routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (p->id % 2 == 0)
		usleep(1000);
	while (!simulation_finished(p->data))
	{
		eat(p);
		if (simulation_finished(p->data))
			break ;
		print_status(p, "is sleeping\n");
		smart_sleep(p->data->time_to_sleep, p->data);
		if (simulation_finished(p->data))
			break ;
		print_status(p, "is thinking\n");
		if (p->data->num_philos % 2 && p->id % 2)
			usleep(p->data->time_to_eat * 500);
	}
	return (NULL);
}
