/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:16:15 by mlima-si          #+#    #+#             */
/*   Updated: 2025/09/10 17:25:13 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int ac, char **av)
{
	if (ac != 5)
		return (0);
	printf("teste");
}
/* -------------------- time funcs ----------------------
int usleep(useconds_t usec);
int gettimeofday(struct timeval *restrict tv, struct timezone *restrict tz);

------------------- tthread funcs ---------------------
int pthread_create(pthread_t *restrict thread,
       const pthread_attr_t *restrict attr,
       void *(*start_routine)(void *),
       void *restrict arg);
int pthread_join(pthread_t thread, void **retval);

------------------ mutex funcs -------------------------

int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex); */