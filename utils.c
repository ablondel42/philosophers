/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:11:28 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/11 14:08:09 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	timer(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	current_timer(void)
{
	g_add.r = timer() - g_add.t;
}

int	ft_atoi(char *s)
{
	int	n;
	int	neg;

	n = 0;
	neg = 1;
	if (!s)
		return (-1);
	if (*s == '-')
	{
		neg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *s++ - '0';
	return (n * neg);
}

void	ft_putnbr(int n)
{
	char	*base;
	char	t[12];
	int		i;

	i = 0;
	base = "0123456789";
	while (n >= 10)
	{
		t[i] = base[n % 10];
		n /= 10;
		i++;
	}
	t[i] = base[n % 10];
	while (i >= 0)
	{
		write(1, &t[i], 1);
		i--;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
