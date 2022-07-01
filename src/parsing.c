//
// Created by Romaine Senelle on 6/24/22.
//

#include "../includes/cub3d.h"

void parsing(char *map_name, t_all *s_all)
{
	int	fd;

	fd = check_map_file(map_name);
	set_params(s_all, fd);
//	making_map(map_name, s_all);
}

int	check_map_file(char *map_name)
{
	int	fd;

	if ((ft_strlen(map_name) < 4) || ft_strncmp(map_name + (ft_strlen(map_name) - 4), ".cub", 4))
		ft_error("Invalid map file");
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		ft_error(NULL);
	if (read(fd, NULL, 0) < 0)
		ft_error(NULL);
	return (fd);
}

void	set_params(t_all *s_all, int fd)
{
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		if (!s || is_map_beginning(s))
		{
			if (s)
				free(s);
			break ;
		}
		check_param(s, s_all);
		free(s);
	}
	close(fd);
}

int	is_map_beginning(char *s)
{
	if (s == 0 || *s == 0)
		return (0);
	while(*s && *s != '\n')
	{
		if (*s != ' ' && *s != '1' && *s != '\t')
			return (0);
		s++;
	}
	return (1);
}

void	check_param(char *s, t_all *s_all)
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

////карту в листы, а потом листы в массив
