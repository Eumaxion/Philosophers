/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:18:07 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/25 19:45:30 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philo *p, char *msg)
{
	int	current_time;

	pthread_mutex_lock(&p->data->print_mutex);
	current_time = get_time() - p->data->start_time;
	if (!simulation_finished(p->data))
	{
		ft_putnbr_fd(current_time, 1);
		write(1, " ", 1);
		ft_putnbr_fd(p->id, 1);
		write(1, " ", 1);
		ft_putstr_fd(msg, 1);
	}
	pthread_mutex_unlock(&p->data->print_mutex);
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	negt;
	int	result;

	i = 0;
	negt = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			negt *= -1;
		}
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * negt);
}

long	ft_atol(const char *nptr)
{
	long	i;
	long	result;
	int		negt;

	i = 0;
	negt = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			negt *= -1;
		}
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * negt);
}
