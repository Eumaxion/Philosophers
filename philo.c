/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:16:15 by mlima-si          #+#    #+#             */
/*   Updated: 2026/03/10 13:30:22 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Invalid input.\n\nUsage: ./philo number_of_philosophers "
			"time_to_die time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (!check_arg_is_int(argv[i]) || ft_atoi(argv[i]) <= 0)
		{
			printf("Invalid input: All arguments must be positive integers.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;

	check_args(argc, argv);
	init_data(&table, argc, argv);
	simulation(&table);
	free_data(&table);
	return (EXIT_SUCCESS);
}