/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:29:46 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 09:30:10 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_has_taken_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->total_ptr->forks[philo->nb - 1]);
	if (ft_launch_action(philo, " has taken a fork\n") == 0)
	{
		pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb - 1]);
		return (0);
	}
	return (1);
}

int	ft_has_taken_right_fork(t_philo *philo)
{
	if (philo->nb != philo->total_ptr->nb_philo)
		pthread_mutex_lock(&philo->total_ptr->forks[philo->nb]);
	else
		pthread_mutex_lock(&philo->total_ptr->forks[0]);
	if (ft_launch_action(philo, " has taken a fork\n") == 0)
	{
		pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb - 1]);
		if (philo->nb != philo->total_ptr->nb_philo)
			pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb]);
		else
			pthread_mutex_unlock(&philo->total_ptr->forks[0]);
		return (0);
	}
	return (1);
}

int	ft_is_eating(t_philo *philo)
{
	philo->last_eat = ft_get_time() - philo->total_ptr->start;
	if (philo->last_eat < 0)
		return (ft_error_and_return(philo->total_ptr, "Could not get time\n"));
	pthread_mutex_lock(&philo->mutex_check);
	if (ft_launch_action(philo, " is eating\n") == 0)
	{
		pthread_mutex_unlock(&philo->mutex_check);
		pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb - 1]);
		if (philo->nb != philo->total_ptr->nb_philo)
			pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb]);
		else
			pthread_mutex_unlock(&philo->total_ptr->forks[0]);
		return (0);
	}
	philo->nb_has_eaten++;
	if (philo->nb_has_eaten == philo->total_ptr->nb_must_eat)
		philo->total_ptr->philos_who_ate_enough++;
	usleep(philo->total_ptr->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb - 1]);
	if (philo->nb != philo->total_ptr->nb_philo)
		pthread_mutex_unlock(&philo->total_ptr->forks[philo->nb]);
	else
		pthread_mutex_unlock(&philo->total_ptr->forks[0]);
	pthread_mutex_unlock(&philo->mutex_check);
	return (1);
}

int	ft_is_sleeping(t_philo *philo)
{
	if (ft_launch_action(philo, " is sleeping\n") == 0)
		return (0);
	usleep(philo->total_ptr->time_to_sleep * 1000);
	return (1);
}

int	ft_is_thinking(t_philo *philo)
{
	if (ft_launch_action(philo, " is thinking\n") == 0)
		return (0);
	if (philo->nb_has_eaten == philo->total_ptr->nb_must_eat)
		return (0);
	return (1);
}
