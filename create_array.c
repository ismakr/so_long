/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:34:49 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/20 02:56:02 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_height(char *fl)
{
	int	fd;
	int	h;
	char	*line;

	fd = open(fl, O_RDONLY);
	line = get_next_line(fd);
	h = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		h++;
	}
	get_next_line(-1);
	return (h);
}

int	ft_get_width(char *fl)
{
	int	fd;
	int	w;
	char	*line;

	fd = open(fl, O_RDONLY);
	line = get_next_line(fd);
	w = ft_strlen(line);
	while (line)
	{
		if (w != ft_strlen(line))
			return (0);
		w = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	return (w);
}

void	ft_create_array(t_long *stc, char *fl)
{
	stc->h = ft_get_height(fl);
        stc->w = ft_get_width(fl);
	stc->arr = NULL;
}
/*
char	**ft_create_array(char *fl)
{
	char	**arr;
}*/
