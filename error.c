/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:00 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 09:53:52 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error_values(int ac, char **av)
{
	if (!((ac == 5 || ac == 6) && ft_strcmp(av[1], "1") == 0))
		write(2,
			"Usage: ./philosophers number_of_philosophers \
time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]\n", 128);
	return (0);
}

int	ft_error_and_return(t_total *total, char *phrase)
{
	write(2, phrase, ft_strlen(phrase));
	ft_free_and_destroy(total);
	return (0);
}
