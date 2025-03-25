/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:19:15 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 18:30:07 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'P' && line[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_exist(char *str)
{
	int	i;
	int	cn;

	i = 0;
	cn = 0;
	while (str[i])
	{
		if (str[i] == 'E' || str[i] == 'P')
			cn++;
		i++;
	}
	if (cn != 2)
		return (0);
	i = 0;
	cn = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			cn++;
		i++;
	}
	if (cn == 0)
		return (0);
	return (1);
}
