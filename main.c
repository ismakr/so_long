/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:49:53 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/20 02:56:00 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file(char *fl)
{
	int	fd;

	if (ft_strnstr(fl, ".ber", ft_strlen(fl)) == 0)
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

int main(int ac, char *av[])
{
	t_long	*main_sct;

	if (ac != 2)
		return (1);
	main_sct = malloc(sizeof(t_long));
	if (main_sct == NULL)
		exit(1);
	ft_check_file(av[1]);
	ft_parse(av[1]);
	ft_create_array(main_sct, av[1]);
	ft_check_wall(main_sct);
	printf("%d\n", main_sct->h);
	printf("%d\n", main_sct->w);
}
