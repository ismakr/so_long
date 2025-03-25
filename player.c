/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 03:10:12 by isakrout         ###   ########.fr       */
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

void ft_win(t_long *sct)
{
	ft_free_sct(sct);
	write(1, "you win\n", 9);
	exit(0);
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
	{
		if (sct->collectible == 0)
			ft_win(sct);
		else
		{
			sct->arr[sct->py + my][sct->px + mx] = 'P';
			sct->arr[sct->py][sct->px] = '0';
			sct->if_exit = 1;
		}
	}
	else if (sct->if_exit == 1)
	{
		sct->arr[sct->py][sct->px] = 'E';
		sct->if_exit = 0;
	}
	else
		sct->arr[sct->py][sct->px] = '0';
	sct->py += my;
	sct->px += mx;
	sct->arr[sct->py][sct->px] = 'P';
	sct->moves++;
	printf("moves%d\n", sct->moves);
	ft_load_images(sct);
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