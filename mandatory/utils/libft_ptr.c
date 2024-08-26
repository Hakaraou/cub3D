/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:19:02 by hakaraou          #+#    #+#             */
/*   Updated: 2024/08/26 16:31:20 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		len1;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	s2 = (char *)malloc(len1 + 1);
	if (!s2)
		return (NULL);
	i = -1;
	while (++i < len1)
		s2[i] = s1[i];
	s2[i] = 0;
	return (s2);
}