/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:56:11 by rsenelle          #+#    #+#             */
/*   Updated: 2022/01/25 17:01:10 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	pars_minus(const char *str, int *i, long int *n)
{
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*n *= -1;
		(*i)++;
		if (str[*i] == '-' || str[*i] == '+')
			return (0);
	}
	return (1);
}

int	ft_atoi_ps(const char *str, int *num)
{
	int			i;
	long int	n;
	long int	k;

	i = 0;
	n = 1;
	k = 0;
	while (((str[i] >= 7) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if (!pars_minus (str, &i, &n))
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = (k * 10) + str[i] - '0';
		if ((k * n) > 2147483647)
			return (1);
		if ((k * n) < -2147483648)
			return (1);
		i++;
	}
	*num = k * n;
	return (0);
}
