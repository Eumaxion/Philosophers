/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:11:55 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/16 17:19:01 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_number(char *s)
{
	int i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || ac > 6)
	{
		printf("usage: ./philo number_of_philosophers time_to_die time_to_eat\
				time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	i = 1;
	while (i < ac)
		if (!is_number(av[i++]))
			return (printf("Error\n"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	monitor_thread;
	int			i;

	if (parse_args(argc, argv))
		return (1);
	init_data(&data, argc, argv);
	init_philos(&data);
	data.start_time = get_time();
	i = -1;
	while (++i < data.num_philos)
		pthread_create(&data.philos[i].thread, NULL,
			philo_routine, &data.philos[i]);
	pthread_create(&monitor_thread, NULL, monitor, &data);
	i = -1;
	while (++i < data.num_philos)
		pthread_join(data.philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
	cleanup(&data);
	return 0;
}
