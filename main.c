/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:11:55 by mlima-si          #+#    #+#             */
/*   Updated: 2026/03/27 13:31:00 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	{
		if (ft_atoi(av[i]) < 0)
		{
			printf("all arguments should be integers and positives\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	*table;

	if (parse_args(ac, av))
		return (1);
 	init_args(table, ac, av);
	simulation();
	destry();
	return (0);
}