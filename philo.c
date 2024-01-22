/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:40:52 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/14 11:03:21 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one(int id)
{
	ft_think(id);
	pthread_mutex_lock(&g_add.print_lock);
	ft_putnbr(g_add.r);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, FORK, ft_strlen(FORK));
	usleep(g_add.time_to_die);
	ft_putnbr(g_add.time_to_die / 1000);
	write(1, " ", 1);
	ft_putnbr(id);
	write(1, DIED, ft_strlen(DIED));
	exit(EXIT_FAILURE);
}

void	test(int left, int right, int id)
{
	if (g_add.state[id] == HUNGRY
		&& g_add.state[left] != EATING
		&& g_add.state[right] != EATING)
	{
		g_add.state[id] = EATING;
		ft_eat(id);
	}
}

void	ft_update(int id)
{
	g_add.last_meal[id] = g_add.r;
	g_add.nb_of_meals[id]--;
	g_add.total_meals--;
	if (g_add.total_meals == 0)
		exit(EXIT_SUCCESS);
}

void	*philosophe(void *arg)
{
	int	left;
	int	right;

	while (1)
	{
		current_timer();
		left = (*(int *)arg - 1);
		right = *(int *)arg;
		if (right == g_add.nb_of_philo)
			right = 0;
		usleep(100);
		if (g_add.nb_of_meals[*(int *)arg] != 0)
		{
			ft_think(*(int *)arg);
			ft_lock(left, right, *(int *)arg);
			usleep(g_add.time_to_eat);
			ft_unlock(left, right);
			ft_update(*(int *)arg);
			ft_sleep(*(int *)arg);
			usleep(g_add.time_to_slp);
		}
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac >= 5)
	{
		init(av);
		i = -1;
		while (++i < g_add.nb_of_philo)
		{
			g_add.idx[i] = i + 1;
			g_add.state[i] = THINKING;
		}
		ft_init_all();
		i = -1;
		while (++i < g_add.nb_of_philo)
			pthread_join(g_add.p[i], NULL);
		ft_destroy_all();
	}
}
