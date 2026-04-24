/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:14 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/24 18:04:56 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int	init_data(t_data *data, int ac, char **av)
{
	int i;

	data->num_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->must_eat = -1;
	data->start_time = get_time();
	if (data->num_philos <= 0 || data->time_to_die <= 0 
		|| data->time_to_sleep <= 0)
		return (ARGS_ERROR);
	if (ac == 6)
		data->must_eat = ft_atol(av[5]);
		if (data->must_eat <= 0)
			return (ARGS_ERROR);
	data->simulation_end = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (MALLOC_ERROR);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (MALLOC_ERROR);
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			free_forks(data, i);	
			return (MUTEX_ERROR);
		}
		i++;
	}
	return (0);
}

static int	init_philos(t_data *data)
{
	int i;

	i = 0;
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (MUTEX_ERROR);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (MUTEX_ERROR);
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
	return (0);
}

int	init_args(t_data *data, int ac, char **av)
{
	int	data_checker;
	int	philo_checker;
	int	fork_checker;

	data_checker = init_data(data, ac, av);
	if (data_checker != 0)
		return (error_exit(data_checker));
	fork_checker = init_forks(data);
	if (fork_checker != 0)
		return (error_exit());
	philo_checker = init_philos(data);
	if (philo_checker != 0)
		return (error_exit(philo_checker));
	return (0);
}
