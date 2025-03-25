/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 23:34:49 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 18:30:25 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_height(char **arr)
{
	int	h;
	int	i;

	i = 0;
	h = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) == 0 || ft_check_char(arr[i]) == 0)
			return (0);
		i++;
		h++;
	}
	return (h);
}

int	ft_get_width(char **arr)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (arr[i] != NULL)
		w = ft_strlen(arr[i]);
	i++;
	while (arr[i])
	{
		if (w != ft_strlen(arr[i]))
			return (0);
		w = ft_strlen(arr[i]);
		i++;
	}
	return (w);
}

int	ft_create_array(t_long *stc, char *map_file)
{
	if (ft_check_exist(map_file) == 0)
		return (0);
	stc->arr = ft_split(map_file, '\n');
	if (stc->arr == NULL)
		return (0);
	stc->h = ft_get_height(stc->arr);
	if (stc->h <= 2)
		return (ft_free_array(stc->arr), 0);
        stc->w = ft_get_width(stc->arr);
	if (stc->w <= 2)
		return (ft_free_array(stc->arr), 0);
	return (1);
}
/*
 * ft_create_array
 * i created an array for map and its hight and width:
 * first i checked if P and E and C exists, and then calculate the h and w
 * it returns 0 on failure
 *
 *
 * ft_get_width
 * cal  the w:
 * i checked if size is invalid
 *
 * ft_get_height
 * cal the h:
 * i chekced if empty line exist and invalid characters
 */