/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:27:53 by rsenelle          #+#    #+#             */
/*   Updated: 2022/07/07 14:29:02 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_params(t_all *s_all, int fd)
{
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		if (!s || is_map(s))
		{
			if (s)
				free(s);
			break ;
		}
		choose_param(s, s_all);
		free(s);
	}
	get_textures(s_all);
	close(fd);
}

void	choose_param(char *s, t_all *s_all)
{
	char	*floor;
	char	*ceilling;

	if (!ft_strncmp(s, "NO ", 3))
		s_all->no = ft_strdup(skip_space(s + 2));
	else if (!ft_strncmp(s, "SO ", 3))
		s_all->so = ft_strdup(skip_space(s + 2));
	else if (!ft_strncmp(s, "WE ", 3))
		s_all->we = ft_strdup(skip_space(s + 2));
	else if (!ft_strncmp(s, "EA ", 3))
		s_all->ea = ft_strdup(skip_space(s + 2));
	else if (!ft_strncmp(s, "F ", 2))
	{
		floor = ft_strdup(skip_space(s + 2));
		s_all->floor = parse_color(floor);
		free(floor);
	}
	else if (!ft_strncmp(s, "C ", 2))
	{
		ceilling = ft_strdup(skip_space(s + 2));
		s_all->ceilling = parse_color(ceilling);
		free(ceilling);
	}
}

int	parse_color(char *color)
{
	int		rgb[3];
	int		i;
	int		res;

	i = 0;
	if (consist_of_num_or_coma(color))
		ft_error("Wrong floor or ceilling color");
	while (i < 3)
	{
		rgb[i] = ft_atoi(color);
		while (*color && *color != ',')
			color++;
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error("Wrong color number");
		color++;
		i++;
	}
	res = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (res);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	get_textures(t_all *s_all)
{
	if (!s_all->no || !s_all->ea || !s_all->so || !s_all->we)
		ft_error("Not all params are set");
	s_all->n_img.img = mlx_xpm_file_to_image(s_all->mlx, \
	s_all->no, &s_all->n_img.width, &s_all->n_img.heigth);
	s_all->s_img.img = mlx_xpm_file_to_image(s_all->mlx, \
	s_all->so, &s_all->s_img.width, &s_all->s_img.heigth);
	s_all->w_img.img = mlx_xpm_file_to_image(s_all->mlx, \
	s_all->we, &s_all->w_img.width, &s_all->w_img.heigth);
	s_all->e_img.img = mlx_xpm_file_to_image(s_all->mlx, \
	s_all->ea, &s_all->e_img.width, &s_all->e_img.heigth);
	if (!s_all->n_img.img || !s_all->s_img.img || !s_all->w_img.img || \
	!s_all->e_img.img)
		ft_error("Wrong texture path");
	s_all->n_img.addr = mlx_get_data_addr(s_all->mlx, \
&s_all->n_img.bits_per_pixel, &s_all->n_img.line_length, &s_all->n_img.endian);
	s_all->s_img.addr = mlx_get_data_addr(s_all->mlx, \
&s_all->s_img.bits_per_pixel, &s_all->s_img.line_length, &s_all->s_img.endian);
	s_all->w_img.addr = mlx_get_data_addr(s_all->mlx, \
&s_all->w_img.bits_per_pixel, &s_all->w_img.line_length, &s_all->w_img.endian);
	s_all->e_img.addr = mlx_get_data_addr(s_all->mlx, \
&s_all->e_img.bits_per_pixel, &s_all->e_img.line_length, &s_all->e_img.endian);
}
