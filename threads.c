/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:15:24 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/14 10:44:23 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(char **av)
{
	int	i;

	i = 0;
	g_add.nb_of_philo = ft_atoi(av[1]);
	if (g_add.nb_of_philo < 1)
		exit(EXIT_FAILURE);
	g_add.time_to_die = ft_atoi(av[2]) * 1000;
	g_add.time_to_eat = ft_atoi(av[3]) * 1000;
	g_add.time_to_slp = ft_atoi(av[4]) * 1000;
	if (g_add.nb_of_philo < 1 || g_add.time_to_slp <= 1
		|| g_add.time_to_die <= 1 || g_add.time_to_eat <= 1)
		exit(EXIT_FAILURE);
	if (g_add.nb_of_philo == 1)
		ft_one(1);
	g_add.times_eaten = ft_atoi(av[5]);
	if (g_add.times_eaten < 1)
		g_add.times_eaten = INT_MIN;
	g_add.total_meals = g_add.times_eaten * g_add.nb_of_philo;
	g_add.diff = g_add.time_to_die / 1000;
	while (++i <= g_add.nb_of_philo)
		g_add.nb_of_meals[i] = g_add.times_eaten;
	g_add.t = timer();
}

void	ft_init_all(void)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&g_add.print_lock, NULL) != 0)
		exit(EXIT_FAILURE);
	while (++i < g_add.nb_of_philo)
		if (pthread_mutex_init(&g_add.forks[i], NULL) != 0)
			exit(EXIT_FAILURE);
	i = -1;
	while (++i < g_add.nb_of_philo)
	{
		if (pthread_create(&g_add.p[i], NULL,
				philosophe, (void *)&(g_add.idx[i])) != 0)
			exit(EXIT_FAILURE);
	}
}

void	ft_destroy_all(void)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&g_add.print_lock);
	while (++i < g_add.nb_of_philo)
		pthread_mutex_destroy(&g_add.forks[i]);
}
