/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:14 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/16 17:17:08 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	init_data(t_data *data, int ac, char **av)
{
	int i;

	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->must_eat = ft_atol(av[5]);
	else
		data->must_eat = -1;
	data->simulation_end = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->death_mutex, NULL);
	i = 0;
	while (i < data->num_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
}

void	init_philos(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
		data->philos[i].data = data;
		i++;
	}
}