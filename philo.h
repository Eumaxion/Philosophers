#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo{
    int         id;
    pthread_t   left_fork;
} t_philo;

typedef struct s_table {
    int     n_philos;
    int     max_hungry_ms;
    int     ms_eat;
    int     ms_sleep;
    int     max_meals;
    t_philo *philos;
} t_table;

int	    main(int ac, char **av);
int	    ft_atoi(const char *nptr);
void    init_args(t_table *table, int ac, char **av);

#endif