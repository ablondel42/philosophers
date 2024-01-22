/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:54:02 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/11 14:15:03 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlock(int left, int right)
{
	if (left < right)
	{
		pthread_mutex_unlock(&g_add.forks[left]);
		pthread_mutex_unlock(&g_add.forks[right]);
	}
	else
	{
		pthread_mutex_unlock(&g_add.forks[right]);
		pthread_mutex_unlock(&g_add.forks[left]);
	}
}

void	ft_lock(int left, int right, int id)
{
	g_add.state[id] = HUNGRY;
	if (left < right)
	{
		pthread_mutex_lock(&g_add.forks[left]);
		pthread_mutex_lock(&g_add.forks[right]);
	}
	else
	{
		pthread_mutex_lock(&g_add.forks[right]);
		pthread_mutex_lock(&g_add.forks[left]);
	}
	ft_fork(id);
	test(left, right, id);
}
