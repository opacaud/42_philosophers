/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:31:44 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 10:04:48 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_total	total;

	if (ac < 5 || ac > 6)
		return (ft_error_values(ac, av));
	if (ft_check_values(ac, av) == 0)
		return (ft_error_values(ac, av));
	if (ft_init(ac, av, &total) == 0)
		return (ft_error_and_return(&total, "Could not initialize data.\n"));
	if (ft_create_threads(&total) == 0)
		return (ft_error_and_return(&total, "Could not create threads\n"));
	ft_free_and_destroy(&total);
	return (0);
}
