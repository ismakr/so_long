/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:49:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/24 03:21:26 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file(char *fl)
{
	int	fd;
	int	len;

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

void	ft_mlx(t_long *sct)
{
	sct->mlx = mlx_init();
        if (sct->mlx == NULL)
                ft_mlx_fail(sct);
        sct->mlx_win = mlx_new_window(sct->mlx, sct->w * 64, sct->h * 64, "Hello world!");
        if (sct->mlx_win == NULL)
                ft_mlx_fail(sct);
}

int main(int ac, char *av[])
{
	t_long	*main_sct;

	if (ac != 2)
		return (1);
	ft_check_file(av[1]);
	main_sct = malloc(sizeof(t_long));
	if (main_sct == NULL)
		exit(1);
	ft_parsing(main_sct, av[1]);
	ft_mlx(main_sct);
	ft_load_images(main_sct);
	mlx_loop(main_sct->mlx);
	//printf("%d\n", main_sct->h);
	//printf("%d\n", main_sct->w);
}
