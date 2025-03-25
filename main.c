/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:49:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 03:12:12 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_check_file(char *fl)
{
	int fd;
	int len;

	len = ft_strlen(fl);
	if (ft_strnstr(&fl[len - 4], ".ber", ft_strlen(fl)) == 0)
	{
		write(2, "invalid file\n", 13);
		exit(1);
	}
	fd = open(fl, O_RDONLY);
	if (fd < 0)
	{
		write(2, "cant open file\n", 15);
		exit(1);
	}
	close(fd);
}

void ft_mlx(t_long *sct)
{
	sct->mlx = mlx_init();
	if (sct->mlx == NULL)
		ft_mlx_fail(sct);
	sct->mlx_win = mlx_new_window(sct->mlx, sct->w * 64, sct->h * 64, "Hello world!");
	if (sct->mlx_win == NULL)
		ft_mlx_fail(sct);
}

int play_hook(int key, t_long *sct)
{
	if (key == 65307)
		ft_esc(sct);
	if (key == 119)
		ft_move_player(sct, 0, -1);
	else if (key == 115)
		ft_move_player(sct, 0, 1);
	else if (key == 100)
		ft_move_player(sct, 1, 0);
	else if (key == 97)
		ft_move_player(sct, -1, 0);
	return (1);
}

int esc_handle(t_long *sct)
{
	ft_esc(sct);
	return (1);
}

int main(int ac, char *av[])
{
	t_long *main_sct;

	if (ac != 2)
		return (1);
	ft_check_file(av[1]);
	main_sct = ft_calloc(1, sizeof(t_long));
	if (main_sct == NULL)
		exit(1);
	ft_parsing(main_sct, av[1]);
	ft_mlx(main_sct);
	ft_load_images(main_sct);
	mlx_key_hook(main_sct->mlx_win, play_hook, main_sct);
	mlx_hook(main_sct->mlx_win, 17, 0, esc_handle, main_sct);
	mlx_loop(main_sct->mlx);
	// printf("%d\n", main_sct->h);
	// printf("%d\n", main_sct->w);
}
