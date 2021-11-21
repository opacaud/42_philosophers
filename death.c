/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:36:49 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/16 13:36:51 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philo_is_dead(t_philo *philo)
{
	int	limit;

	limit = ft_get_time() - philo->total_ptr->start - philo->last_eat;
	if (limit < 0)
		return (ft_error_and_return(philo->total_ptr, "Could not get time\n"));
	if (limit > philo->total_ptr->time_to_die)
		return (1);
	return (0);
}

int	ft_someone_died(t_total *total, t_philo *philo, int i, int now)
{
	char	*time;

	if (total->someone_died == 0)
	{
		if (now - total->philo_tab[i].last_eat > total->time_to_die
			&& total->philo_tab[i].nb_has_eaten != total->nb_must_eat)
		{
			total->time_of_death = now;
			total->someone_died = 1;
			if (total->someone_died == 1 && ft_philo_is_dead(philo))
			{
				total->someone_died = 2;
				time = ft_itoa(total->time_of_death);
				ft_assemble_and_print(philo, time, " died\n");
			}
			pthread_mutex_unlock(&total->dies);
			return (1);
		}
	}
	return (0);
}

int	ft_check_if_stop(t_total *total)
{
	int		i;
	int		now;

	while (1)
	{
		i = 0;
		while (i < total->nb_philo)
		{
			usleep(200);
			now = ft_get_time() - total->start;
			pthread_mutex_lock(&total->philo_tab[i].mutex_check);
			pthread_mutex_lock(&total->dies);
			if (ft_someone_died(total, &total->philo_tab[i],
					total->philo_tab[i].nb - 1, now) == 1)
			{
				pthread_mutex_unlock(&total->philo_tab[i].mutex_check);
				return (0);
			}
			pthread_mutex_unlock(&total->dies);
			pthread_mutex_unlock(&total->philo_tab[i].mutex_check);
			if (total->philos_who_ate_enough
				== total->nb_philo)
				return (0);
		}
	}
}
