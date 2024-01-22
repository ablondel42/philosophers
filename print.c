/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:55:50 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/14 11:07:29 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_dead(int id)
{
	current_timer();
	pthread_mutex_lock(&g_add.print_lock);
	if (g_add.r < g_add.diff)
		ft_putnbr(g_add.diff);
	else
		ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, DIED, ft_strlen(DIED));
	exit(EXIT_FAILURE);
}

void	ft_fork(int id)
{
	pthread_mutex_lock(&g_add.print_lock);
	ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, FORK, ft_strlen(FORK));
	ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, FORK, ft_strlen(FORK));
	pthread_mutex_unlock(&g_add.print_lock);
}

void	ft_sleep(int id)
{
	if (g_add.total_meals > 1)
	{
		pthread_mutex_lock(&g_add.print_lock);
		ft_putnbr(g_add.r);
		write(1, " ", 1);
		ft_putnbr(id);
		write(1, SLEEP, ft_strlen(SLEEP));
		pthread_mutex_unlock(&g_add.print_lock);
	}
	g_add.state[id] = THINKING;
}

void	ft_think(int id)
{
	pthread_mutex_lock(&g_add.print_lock);
	ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, THINK, ft_strlen(THINK));
	pthread_mutex_unlock(&g_add.print_lock);
}

void	ft_eat(int id)
{
	current_timer();
	if (g_add.last_meal[id] == 0 || g_add.last_meal[id] > g_add.nb_of_philo)
	{
		g_add.limit = g_add.last_meal[id] + g_add.diff;
		if (g_add.r >= g_add.limit)
			ft_print_dead(id);
	}
	g_add.last_meal[id] = 0;
	pthread_mutex_lock(&g_add.print_lock);
	ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, EAT, ft_strlen(EAT));
	pthread_mutex_unlock(&g_add.print_lock);
}
