/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:01:59 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 03:12:28 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_struct_fail(char *str, t_long *ptr, char *map_file)
{       
        free(ptr);
        free(map_file);
        ft_error_message(str);
        exit(1);
}

void	ft_invalid_ch(char *str)
{
	free(str);
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
	ft_error_message("invalid wall\n");
	exit(1);
}

void	ft_mlx_fail(t_long *sct)
{
	ft_free_sct(sct);
	ft_error_message("mlx fail\n");
}
