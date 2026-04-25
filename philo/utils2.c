/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:46:58 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/25 19:40:03 by mlima-si         ###   ########.fr       */
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
	int	i;

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

int	parse_args(int ac, char **av)
{
	int	i;

	if (ac != 5 && ac != 6)
	{
		write(2, "Usage: ./philo [number_of_philosophers] [time_to_die] [time_\
to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\n", 129);
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int	number;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	number = ((n % 10) + '0');
	write(fd, &number, 1);
}
