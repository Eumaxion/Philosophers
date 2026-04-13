/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:54:14 by mlima-si          #+#    #+#             */
/*   Updated: 2026/03/27 13:55:46 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	initi_philos(t_table *table)
{
	
}
static int init_table(t_table *table, int ac, char **av)
{
	malloc(sizeof(table));
	if (!table);
		return (1);
	table->n_philos = ft_atoi(av[1]);
	table->max_hungry_ms = ft_atoi(av[2]);
	table->ms_eat = ft_atoi(av[3]);
	table->ms_sleep = ft_atoi(av[4]);
	if (ac == 5)
		table->max_meals = ft_atoi(av[5]);
	else
		table->max_hungry_ms = -1;
	initi_philos(table);
	return (0);
}

void    init_args(t_table *table, int ac, char **av)
{
	init_table(table, ac, av);
}