/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:13 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/18 08:50:00 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_and_destroy(t_total *total)
{
	int	i;

	i = 0;
	while (i < total->nb_philo)
	{
		pthread_mutex_destroy(&total->forks[i]);
		pthread_mutex_destroy(&total->philo_tab[i].mutex_check);
		i++;
	}
	pthread_mutex_destroy(&total->dies);
	if (total->threads)
		free(total->threads);
	if (total->philo_tab)
		free(total->philo_tab);
	if (total->forks)
		free(total->forks);
}
