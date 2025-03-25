/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:57:26 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 03:21:08 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_sct(t_long *sct)
{
	if (sct->mlx)
	{
		if (sct->floor)
			mlx_destroy_image(sct->mlx, sct->floor);
		if (sct->wall)
			mlx_destroy_image(sct->mlx, sct->wall);
		if (sct->collect)
			mlx_destroy_image(sct->mlx, sct->collect);
		if (sct->player)
			mlx_destroy_image(sct->mlx, sct->player);
		if (sct->exit)
			mlx_destroy_image(sct->mlx, sct->exit);
		if (sct->mlx_win)
		{
			mlx_clear_window(sct->mlx, sct->mlx_win);
			mlx_destroy_window(sct->mlx, sct->mlx_win);
		}
		mlx_destroy_display(sct->mlx);
		free(sct->mlx);
	}
	ft_free_array(sct->arr);
	free(sct);
}

void	ft_esc(t_long *sct)
{
	ft_free_sct(sct);
	write(1, "exit\n", 6);
	exit(0);
}
