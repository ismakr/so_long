/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:53:10 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/20 02:54:38 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != 'E' && line[i] != '0' && line[i] != '1'
				&& line[i] != 'P' && line[i] != 'C')
			ft_invalid_ch(line);
		i++;
	}
}

void	ft_chech_wall(to_long *stc)
{
}

void	ft_parse(char *fl)
{
	int	fd;
	char	*line;
	int	i;

	i = 0;
	fd = open(fl, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		ft_error_message("empty file\n");
	while (line != NULL)
	{
		if (ft_strlen(line) == 1)
			ft_empty_line(line);
		ft_check_char(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (i < 3)
		ft_error_message("invalid map");
}
