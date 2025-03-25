/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 02:02:23 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 03:00:16 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_fail(t_long *sct)
{
	ft_free_sct(sct);
	ft_error_message("image fail\n");
}

void	ft_put_images(t_long *sct)
{
	int	i;
	int	j;

	i = 0;
	while (sct->arr[i])
	{
		j = 0;
		while (sct->arr[i][j])
		{
			if (sct->arr[i][j] == '1')
				mlx_put_image_to_window(sct->mlx, sct->mlx_win, sct->wall, j * 64, i * 64);
			else if (sct->arr[i][j] == '0')
				mlx_put_image_to_window(sct->mlx, sct->mlx_win, sct->floor, j * 64, i * 64);
			else if (sct->arr[i][j] == 'E')
				mlx_put_image_to_window(sct->mlx, sct->mlx_win, sct->exit, j * 64, i * 64);
			else if (sct->arr[i][j] == 'C')
				mlx_put_image_to_window(sct->mlx, sct->mlx_win, sct->collect, j * 64, i * 64);
			else if (sct->arr[i][j] == 'P')
				mlx_put_image_to_window(sct->mlx, sct->mlx_win, sct->player, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	ft_load_images(t_long *sct)
{
	sct->floor = mlx_xpm_file_to_image(sct->mlx, "textures/floor.xpm", &(int){64}, &(int){64});
	sct->wall = mlx_xpm_file_to_image(sct->mlx, "textures/wall.xpm", &(int){64}, &(int){64});
	sct->exit = mlx_xpm_file_to_image(sct->mlx, "textures/exit.xpm", &(int){64}, &(int){64});
	sct->player = mlx_xpm_file_to_image(sct->mlx, "textures/player.xpm", &(int){64}, &(int){64});
	sct->collect = mlx_xpm_file_to_image(sct->mlx, "textures/collect.xpm", &(int){64}, &(int){64});
	if (sct->floor == NULL || sct->wall == NULL || sct->exit == NULL || sct->player == NULL || sct->collect == NULL)
		ft_image_fail(sct);
	ft_put_images(sct);
}
