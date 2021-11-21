/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:25 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 10:01:24 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_null(t_total *total)
{
	total->nb_philo = 0;
	total->time_to_die = 0;
	total->time_to_eat = 0;
	total->time_to_sleep = 0;
	total->nb_must_eat = -1;
	total->threads = 0;
	total->philo_tab = 0;
	total->forks = 0;
	total->start = 0;
	total->now = 0;
	total->time_of_death = 0;
	total->someone_died = 0;
	total->philos_who_ate_enough = 0;
}

void	ft_init_philo_tab(t_total *total)
{
	int	i;

	i = 0;
	while (i < total->nb_philo)
	{
		total->philo_tab[i].nb = i + 1;
		total->philo_tab[i].last_eat = 0;
		total->philo_tab[i].nb_has_eaten = 0;
		pthread_mutex_init(&total->philo_tab[i].mutex_check, NULL);
		total->philo_tab[i].total_ptr = total;
		i++;
	}
}

void	ft_init_atoi(t_total *total, int ac, char **av)
{
	total->nb_philo = ft_atoi(av[1]);
	total->time_to_die = ft_atoi(av[2]);
	total->time_to_eat = ft_atoi(av[3]);
	total->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		total->nb_must_eat = ft_atoi(av[5]);
}

int	ft_init(int ac, char **av, t_total *total)
{
	int	i;

	ft_init_null(total);
	ft_init_atoi(total, ac, av);
	total->philo_tab = malloc(sizeof(t_philo) * total->nb_philo);
	if (total->philo_tab == 0)
		return (0);
	ft_init_philo_tab(total);
	total->threads = malloc(sizeof(pthread_mutex_t) * total->nb_philo);
	if (total->threads == 0)
		return (0);
	total->forks = malloc(sizeof(pthread_mutex_t) * total->nb_philo);
	if (total->forks == 0)
		return (0);
	i = 0;
	while (i < total->nb_philo)
	{
		pthread_mutex_init(&total->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&total->starter, NULL);
	pthread_mutex_init(&total->dies, NULL);
	return (1);
}
