/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:51:42 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 17:53:07 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_win(t_long *sct)
{
	sct->moves++;
	write(1, "moves: ", 7);
	ft_putnbr_fd(sct->moves, 1);
	write(1, "\n", 1);
	ft_free_sct(sct);
	write(1, "you win\n", 8);
	exit(0);
}

void	ft_exit_handle(t_long *sct, int mx, int my)
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