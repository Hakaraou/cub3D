/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:44:29 by hakaraou          #+#    #+#             */
/*   Updated: 2024/08/26 19:33:05 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	j;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (len > lens - start)
		len = lens - start;
	if (start > lens)
		len = 0;
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (0);
	j = 0;
	while (j < len)
	{
		s1[j] = s[start];
		j++;
		start++;
	}
	s1[j] = 0;
	return (s1);
}

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

int dir_picker(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (E_NO);
	if (!ft_strncmp(line, "SO", 2))
		return (E_SO);
	if (!ft_strncmp(line, "WE", 2))
		return (E_WE);
	if (!ft_strncmp(line, "EA", 2))
		return (E_EA);
	return (-1);
}

static int	set_param_1(t_texture *texture, char *line)
{
	int i = 0;
	int j = 0;

	texture->identifier = dir_picker(line);
	if (texture->identifier == (t_id)-1)
		return (EXIT_FAILURE);
	line += 2;
	while (line[i] && is_white_space(line[i]))
		i++;
	if (!i)
		return (EXIT_FAILURE);
	while (line[i + j] && !is_white_space(line[i + j]))
		j++;
	texture->path = ft_substr(line, i, j);
	return (0);
}

int is_line_space(char *line)
{
	int	i;

	i = -1;
	while (is_white_space(line[++i]))
		;
	if (line[i])
		return (0);
	return (1);
}

static int	creat_param(t_param *param, char *name_file)
{
	int		fd;
	char	*line_maps_file;
	int		i;

	fd = 0;
	line_maps_file = NULL;
	fd = open(name_file, O_RDONLY, 0400);
	if (fd == -1)
		return (ft_putendl_fd("error: open", 2), -1);
	i = 1;
	while (1)
	{
		free(line_maps_file);
		line_maps_file = get_next_line(fd);
		if (!line_maps_file)
			break ;
		if (is_line_space(line_maps_file))
			continue ;
		if (i < 5 && set_param_1(&param->texture[i - 1], line_maps_file) == -1)
			return (free(line_maps_file), -1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_param	param;
	if (ac != 2)
		return (ft_putendl_fd("ERROR", 2), -1);
	creat_param(&param, av[1]);
	for (int i = 0; i < 4; i++)
		printf("|%d| %s\n", param.texture[i].identifier, param.texture[i].path);
	return (0);
}
