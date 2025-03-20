/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:01:59 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/20 02:37:04 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_empty_line(char *ptr)
{
	free(ptr);
	get_next_line(-1);
	ft_error_message("empty line\n");
}

void	ft_invalid_ch(char *str)
{
	free(str);
	get_next_line(-1);
	ft_error_message("invalid char\n");
}

void	ft_error_message(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

void	ft_invalid_wall(char *str)
{
	free(str);
	get_next_line(-1);
	ft_error_message("invalid wall\n");
	exit(1);
}
