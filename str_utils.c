/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:33:42 by opacaud           #+#    #+#             */
/*   Updated: 2021/11/15 11:09:36 by opacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res);
}

unsigned int	ft_get_length(int nb)
{
	unsigned int	i;
	unsigned int	nb_unsigned;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i = 1;
		nb_unsigned = (unsigned int)(-nb);
	}
	else
	{
		nb_unsigned = (unsigned int)nb;
	}
	while (nb_unsigned > 0)
	{
		i++;
		nb_unsigned /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*res;
	unsigned int	unsigned_n;

	size = ft_get_length(n);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res == 0)
		return (0);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		unsigned_n = (unsigned int) - n;
		res[0] = '-';
	}
	else
		unsigned_n = (unsigned int)n;
	res[size] = 0;
	while (unsigned_n > 0)
	{
		res[--size] = unsigned_n % 10 + '0';
		unsigned_n /= 10;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	unsigned int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;

	if (s1 == 0 && s2 == 0)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == 0)
		return (0);
	i = -1;
	size = ft_strlen(s1);
	while (++i < size)
		res[i] = s1[i];
	j = -1;
	size = ft_strlen(s2);
	while (++j < size)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free (s1);
	return (res);
}
