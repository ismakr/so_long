/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/23 17:23:46 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_position(t_long *main_sct)
{
	int	i;
	int	j;

	i = 0;
	while  (main_sct->arr[i])
	{
		j = 0;
		while (main_sct->arr[j])
		{
			if (main_sct->arr[i][j] == 'P')
			{
				main_sct->px = j;
				main_sct->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
