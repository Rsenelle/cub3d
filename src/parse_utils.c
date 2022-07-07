/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:40 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:28:59 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_space(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

int	consist_of_num_or_coma(char *s)
{
	size_t	coma;

	coma = 0;
	if (s == 0 || *s == 0)
		return (0);
	while (*s)
	{
		if (*s == ',')
			coma++;
		if ((*s <= '0' || *s >= '9') && *s != ',')
			return (0);
		s++;
	}
	if (coma != 2)
		return (0);
	return (1);
}

int	is_map(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	s = skip_space(s);
	if (!*s)
		return (0);
	while (*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '0' && *s != 'N' && \
		*s != 'W' && *s != 'E' && *s != 'S' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

int	is_map_border(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	while (*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}
