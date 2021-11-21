/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:30:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 09:30:47 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_wait_before_start(t_philo *philo)
{
	if ((philo->total_ptr->nb_philo % 3 == 0
			&& philo->total_ptr->nb_philo % 2 == 1)
		|| (((philo->total_ptr->nb_philo - 1) % 6) == 0))
	{
		if (philo->nb % 2 == 1)
			usleep(philo->total_ptr->time_to_eat);
	}
	else if (philo->total_ptr->nb_philo % 2 == 1)
	{
		if (philo->nb % 3 == 2)
			usleep(philo->total_ptr->time_to_eat);
		if (philo->nb % 3 == 0)
			usleep(2 * philo->total_ptr->time_to_eat);
	}
	else if (philo->total_ptr->nb_philo % 2 == 0 && philo->nb % 2 == 1)
		usleep(philo->total_ptr->time_to_eat);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->total_ptr->starter);
	pthread_mutex_unlock(&philo->total_ptr->starter);
	ft_wait_before_start(philo);
	philo->last_eat = ft_get_time() - philo->total_ptr->start;
	while (1)
	{
		if (ft_has_taken_left_fork(philo) == 0)
			return (0);
		if (philo->total_ptr->nb_philo == 1)
		{
			pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb - 1]);
			return (0);
		}
		if (ft_has_taken_right_fork(philo) == 0)
			return (0);
		if (ft_is_eating(philo) == 0)
			return (0);
		if (ft_is_sleeping(philo) == 0)
			return (0);
		if (ft_is_thinking(philo) == 0)
			return (0);
	}
}

int	ft_create_threads(t_total *total)
{
	int	i;

	pthread_mutex_lock(&total->starter);
	i = 0;
	while (i < total->nb_philo)
	{
		if (pthread_create(&total->threads[i], NULL, \
		&routine, &total->philo_tab[i]) != 0)
			return (ft_error_and_return(total, "Could not create threads\n"));
		usleep(100);
		i++;
	}
	total->start = ft_get_time();
	pthread_mutex_unlock(&total->starter);
	ft_check_if_stop(total);
	i = 0;
	while (i < total->nb_philo)
	{
		if (pthread_join(total->threads[i], NULL) != 0)
			return (ft_error_and_return(total, "Could not join threads\n"));
		i++;
	}
	if (total->philos_who_ate_enough == total->nb_philo)
		write(1, "number_of_times_each_philosopher_must_eat reached\n", 50);
	return (1);
}
