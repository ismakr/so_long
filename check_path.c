/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 02:40:40 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/23 17:40:18 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **arr, int x, int y)
{
	if (arr[y][x] == '1' || arr[y][x] == 'V')
		return ;
	arr[y][x] = 'V';
	ft_flood_fill(arr, x + 1, y);
	ft_flood_fill(arr, x, y + 1);
	ft_flood_fill(arr, x - 1, y);
	ft_flood_fill(arr, x, y - 1);
}

int	ft_check_flood(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E' || arr[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_path(t_long *main_sct, char *map_file)
{
	char	**arr;
	int	c;

	arr = ft_split(map_file, '\n');
	if (arr == NULL)
		return (0);
	ft_player_position(main_sct);
	ft_flood_fill(arr, main_sct->px, main_sct->py);
	c = ft_check_flood(arr);
	if (c == 0)
		return (ft_free_array(arr), 0);
	return (ft_free_array(arr), 1);
}
