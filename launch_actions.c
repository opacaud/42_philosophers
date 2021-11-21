/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:34 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 10:03:24 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_assemble_and_print(t_philo *philo, char *time, char *phrase)
{
	char	*nb;
	char	*tmp1;
	char	*tmp2;
	char	*res;

	nb = ft_itoa(philo->nb);
	tmp1 = ft_strjoin(time, "ms ");
	tmp2 = ft_strjoin(tmp1, nb);
	res = ft_strjoin(tmp2, phrase);
	write(1, res, ft_strlen(res));
	free(nb);
	free(res);
}

int	ft_launch_action(t_philo *philo, char *phrase)
{
	char	*time;

	if (philo->total_ptr->philos_who_ate_enough == philo->total_ptr->nb_philo
		|| philo->total_ptr->someone_died != 0)
		return (0);
	if (philo->total_ptr->someone_died == 0)
	{
		philo->total_ptr->now = ft_get_time();
		if (philo->total_ptr->now == 0)
		{
			return (ft_error_and_return(philo->total_ptr,
					"Could not get time\n"));
		}
		time = ft_itoa(philo->total_ptr->now - philo->total_ptr->start);
		ft_assemble_and_print(philo, time, phrase);
		return (1);
	}
	return (0);
}
