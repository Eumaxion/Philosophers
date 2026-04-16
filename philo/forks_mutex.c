/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:01:22 by mlima-si          #+#    #+#             */
/*   Updated: 2026/04/16 16:32:05 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *p)
{
	if (p->id % 2 == 0)
	{
		pthread_mutex_lock(p->right_fork);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(p->left_fork);
	}
	else
	{
		pthread_mutex_lock(p->left_fork);
		print_status(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
	}
	print_status(p, "has taken a fork");
}

void	put_forks(t_philo *p)
{
	pthread_mutex_unlock(p->left_fork);
	pthread_mutex_unlock(p->right_fork);
}
