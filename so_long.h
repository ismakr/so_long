/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:54:32 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/24 02:54:33 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include "/usr/include/minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_long
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	char	**arr;
	int	px;
	int	py;
	int	h;
	int	w;
} t_long;
/*strjoin*/
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
/*check_file*/
void	ft_check_file(char *fl);
void	ft_open_fail(char *str);
char    *ft_create_file(char *fl);
/*parse*/
void	ft_parsing(t_long *main_sct, char *fl);
int     ft_check_wall(t_long *main_sct);
int     ft_check_up_down(char *line);
int    ft_check_newline(char *map_file);
/*error*/
void	ft_error_message(char *str);
void	ft_invalid_ch(char *str);
void	ft_empty_line(char *ptr);
void    ft_struct_fail(char *str, t_long *ptr, char *map_file);
void	ft_mlx_fail(t_long *sct);
/*strnstr*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/*create_array*/
int	ft_create_array(t_long *stc, char *map_file);
int	ft_get_height(char **arr);
int	ft_get_width(char **arr);
int	ft_check_exist(char *str);
int	ft_check_char(char *line);
/*split*/
char	**ft_split(char *s, char c);
void	ft_free_array(char **arr);
/*check_path*/
int	ft_check_path(t_long *main_sct, char *map_file);
int	ft_check_flood(char **arr);
void	ft_flood_fill(char **arr, int x, int y);
/*player*/
void	ft_player_position(t_long *main_sct);
/*mlx*/
void    ft_mlx(t_long *sct);
void	ft_load_images(t_long *sct);
void	ft_put_images(t_long *sct);
#endif
