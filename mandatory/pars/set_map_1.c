/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:01:01 by hakaraou          #+#    #+#             */
/*   Updated: 2024/08/29 20:18:06 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_type	set_type_block_1(char c)
{
	if (c == ' ')
		return (E_VOID);
	if (c == '0')
		return (E_EMPTY);
	if (c == '1')
		return (E_BLOCK);
	if (c == 'W')
		return (E_PLAYER_W);
	if (c == 'S')
		return (E_PLAYER_S);
	if (c == 'E')
		return (E_PLAYER_E);
	if (c == 'N')
		return (E_PLAYER_N);
	else
		return (9);
}

static t_type	set_type_block_0(char c)
{
	puts("!!\n\n");
	if (c != '\n')
		return (set_type_block_1(c));
	return (set_type_block_1(' '));
}

static int	put_map(t_cub *cub)
{
	size_t		i;
	size_t		j;
	size_t		k;
	t_line_map	*tmp;

	tmp = cub->line_map;
	j = 0;
	while (tmp && j < cub->height)
	{
		i = cub->ofset_front;
		k = 0;
		while (tmp->line_map[i] && k < cub->width)
		{
		printf("---------- %zu %zu %zu |%c| %d\n", j, k, i, tmp->line_map[i], cub->map[j][k].value);
			cub->map[j][k].value = set_type_block_0(tmp->line_map[i]);
			exit(1);
			if (cub->map[j][k].value == 9)
				return (-1);
			i++;
			k++;
		}
		while (k < cub->width)
		{
			cub->map[j][k].value = set_type_block_1(' ');
			k++;
		}
		j++;
		tmp = tmp->next;
	}
	return (0);
}

int	creat_map(t_cub *cub)
{
	size_t	i;

	i = 0;
	cub->map = malloc(sizeof(t_map *) * cub->height);
	if (!cub->map)
		return (ft_putendl_fd("error: malloc", 2), -1);
	// puts("!!!!!!\n\n");
		printf("---------- %p %zu\n", cub->map, cub->width);
	while (i < cub->height && cub->map[i])
	{
	// printf("!%zu!!\n\n", i);
		cub->map[i] = malloc(sizeof(t_map) * cub->width);
		if (!cub->map[i])
			return (ft_putendl_fd("error: malloc", 2), -1);
		i++;
	}
	// cub->map[i] = NULL;
	if (put_map(cub) == -1)
		return (ft_putendl_fd("ERROR", 2), -1);
	return (0);
}
