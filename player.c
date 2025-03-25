/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 17:52:00 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_player_position(t_long *main_sct)
{
	int i;
	int j;

	i = 0;
	while (main_sct->arr[i])
	{
		j = 0;
		while (main_sct->arr[j])
		{
			if (main_sct->arr[i][j] == 'P')
			{
				main_sct->px = j;
				main_sct->py = i;
				return;
			}
			j++;
		}
		i++;
	}
}

void	ft_move_player_render(t_long *sct, int mx, int my)
{
	sct->py += my;
	sct->px += mx;
	sct->arr[sct->py][sct->px] = 'P';
	sct->moves++;
	write(1, "moves: ", 7);
	ft_putnbr_fd(sct->moves, 1);
	write(1, "\n", 1);
	ft_put_images(sct);
}

void ft_move_player(t_long *sct, int mx, int my)
{
	if (sct->arr[sct->py + my][sct->px + mx] == '1')
		return;
	if (sct->arr[sct->py + my][sct->px + mx] == 'C')
	{
		sct->arr[sct->py][sct->px] = '0';
		sct->collectible--;
	}
	else if (sct->arr[sct->py + my][sct->px + mx] == 'E')
		ft_exit_handle(sct, mx, my);
	else if (sct->if_exit == 1)
	{
		sct->arr[sct->py][sct->px] = 'E';
		sct->if_exit = 0;
	}
	else
		sct->arr[sct->py][sct->px] = '0';
	ft_move_player_render(sct, mx, my);
}

void ft_count_collectible(t_long *sct)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (sct->arr[i])
	{
		j = 0;
		while (sct->arr[i][j])
		{
			if (sct->arr[i][j] == 'C')
				sct->collectible++;
			j++;
		}
		i++;
	}
}