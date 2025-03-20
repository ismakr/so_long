/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:54:32 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/20 02:37:44 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_long
{
	char	**arr;
	int	h;
	int	w;
} t_long;

/*check_file*/
void	ft_check_file(char *fl);
/*parse*/
void	ft_parse(char *fl);
void	ft_check_map(char *fl);
void	ft_check_char(char *line);
void	ft_invalid_wall(char *str);
/*error*/
void	ft_error_message(char *str);
void	ft_invalid_ch(char *str);
void	ft_empty_line(char *ptr);
/*strnstr*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*create_array*/
void	ft_create_array(t_long *stc, char *fl);
int	ft_get_width(char *fl);
int	ft_get_height(char *fl);
#endif
