/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:45:02 by mlima-si          #+#    #+#             */
/*   Updated: 2026/03/13 14:50:43 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->philos[i].last_meal_mutex, NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&table->philos[i].meals_eaten_mutex, NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_mutex_init(&table->philos[i].l_fork_mutex, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&table->someone_died_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&table->min_last_meal_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	destroy_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_destroy(&table->philos[i].last_meal_mutex);
		pthread_mutex_destroy(&table->philos[i].meals_eaten_mutex);
		pthread_mutex_destroy(&table->philos[i].l_fork_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->someone_died_mutex);
	pthread_mutex_destroy(&table->min_last_meal_mutex);
}
