/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:09:15 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/14 10:39:53 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>

# define DIED " died\n"
# define FORK " has taken a fork\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define EAT " is eating\n"
# define THINKING 1
# define HUNGRY 2
# define EATING 3

struct s_philo
{
	pthread_t		p[210];
	int				state[210];
	pthread_mutex_t	forks[210];
	pthread_mutex_t	print_lock;
	int				idx[210];
	int				limit;
	int				left;
	int				right;
	int				last_meal[210];
	int				diff;
	int				nb_of_meals[210];
	int				times_eaten;
	int				total_meals;
	int				dead;
	int				t;
	int				r;
	int				x;
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_slp;
	int				i;
};

struct s_philo	g_add;

size_t	ft_strlen(char *s);
int		timer(void);
void	current_timer(void);
int		ft_atoi(char *s);
void	ft_putnbr(int n);
void	ft_print_dead(int id);
void	ft_fork(int id);
void	ft_eat(int id);
void	ft_sleep(int id);
void	ft_think(int id);
void	*philosophe(void *arg);
void	test(int left, int right, int id);
void	init(char **av);
void	ft_init_all(void);
void	ft_destroy_all(void);
void	ft_unlock(int left, int right);
void	ft_lock(int left, int right, int id);
void	ft_one(int id);

#endif
