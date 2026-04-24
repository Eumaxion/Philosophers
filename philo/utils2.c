/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:46:58 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/24 18:05:51 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_forks(t_data *data, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	data->forks = NULL;
	return ;
}

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

int	error_exit(int n_err)
{
	if (n_err == ARGS_ERROR)
		write(2, "Invalid arguments\n", 18);
	else if (n_err == THREAD_ERROR)
		write(2, "Thread init error\n", 19);
	else if (n_err == MALLOC_ERROR)
		write(2, "Malloc fail\n", 13);
	else if (n_err == MUTEX_ERROR)
		write(2, "Mutex init error\n", 18);
	return (1);
}

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		write(2, "Usage: ./philo [number_of_philosophers] [time_to_die] [time_\
			to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n", 132);
		return (1);
	}
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i++]))
			return (error_exit(ARGS_ERROR));
	}
	return (0);
}
