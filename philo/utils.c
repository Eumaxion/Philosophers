/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:18:07 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/13 20:03:52 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_philo *p, char *msg)
{
	pthread_mutex_lock(&p->data->print_mutex);
	if (!simulation_finished(p->data))
		printf("%ld %d %s\n", get_time() - p->data->start_time, p->id, msg);
	pthread_mutex_unlock(&p->data->print_mutex);
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
