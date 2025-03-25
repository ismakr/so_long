/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:06:38 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 18:22:16 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_up_down(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (c);
}

int	ft_check_wall(t_long *main_sct)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (main_sct->arr[i] != NULL)
	{
		if (ft_check_up_down(main_sct->arr[i]) == 0)
			return (0);
	}
	while (main_sct->arr[i])
	{
		len = ft_strlen(main_sct->arr[i]);
		if (main_sct->arr[i][0] != '1' || main_sct->arr[i][len - 1] != '1')
			return (0);
		i++;
	}
	if (ft_check_up_down(main_sct->arr[i - 1]) == 0)
		return (0);
	return (1);
}

int	ft_check_newline(char *map_file)
{
	int	i;

	i = 0;
	while (map_file[i])
	{
		if (i == 0 && map_file[i] == '\n')
			return (0);
		if (map_file[i] == '\n' && map_file[i + 1] && map_file[i + 1] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_parsing(t_long *main_sct, char *fl)
{
	char	*map_file;

	map_file = ft_create_file(fl);
	if (ft_strlen(map_file) == 0)
		ft_struct_fail("empty file\n", main_sct, map_file);
	if (ft_check_newline(map_file) == 0)
		ft_struct_fail("invalid map\n", main_sct, map_file);
	if (ft_create_array(main_sct, map_file) == 0)
	       	ft_struct_fail("invalid map\n", main_sct, map_file);
	if (ft_check_wall(main_sct) == 0)
	{
		ft_free_array(main_sct->arr);
        ft_struct_fail("invalid map\n", main_sct, map_file);
	}
	if (ft_check_path(main_sct, map_file) == 0)
	{
		ft_free_array(main_sct->arr);
		ft_struct_fail("invalid map\n", main_sct, map_file);
	}
	free(map_file);
	ft_count_collectible(main_sct);
}
