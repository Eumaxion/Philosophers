/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:11:55 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/25 19:37:38 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_thds(t_data *data, t_philo *p)
{
	int			i;
	pthread_t	monitor_thread;

	if (data->num_philos == 1)
	{
		print_status(p, "has taken a fork\n");
		usleep(p->data->time_to_die * 1000);
		print_status(p, "died\n");
		return (0);
	}
	i = -1;
	while (++i < data->num_philos)
		pthread_create(&data->philos[i].thread, NULL,
			philo_routine, &data->philos[i]);
	pthread_create(&monitor_thread, NULL, monitor, data);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	int			data_check;
	t_data		data;

	if (parse_args(argc, argv))
		return (1);
	data_check = init_args(&data, argc, argv);
	if (data_check != 0)
		return (1);
	start_thds(&data, &data.philos[0]);
	cleanup(&data);
	return (0);
}
