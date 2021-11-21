/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:30:21 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 09:30:25 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	*car_spe1;
	unsigned char	*car_spe2;

	i = 0;
	car_spe1 = (unsigned char *)s1;
	car_spe2 = (unsigned char *)s2;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (car_spe1[i] - car_spe2[i]);
}

int	ft_is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_values(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_is_num(av[i]) == 0)
			return (0);
		i++;
	}
	if (ft_strcmp(av[1], "0") == 0 || (av[5] && ft_strcmp(av[5], "0") == 0))
		return (0);
	return (1);
}
