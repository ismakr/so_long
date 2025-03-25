/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:53:10 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/24 17:05:02 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_fail(char *str)
{
	ft_error_message(str);
	exit(1);
}

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*ft_create_file(char *fl)
{
	char	*str;
	char	buff[101];
	char	*ptr;
	ssize_t	rd;
	int	fd;

	fd = open(fl, O_RDONLY);
	if (fd < 0)
		ft_open_fail("open fail\n");
	rd = 1;
	str = malloc(1);
	str[0] = '\0';
	while (rd > 0)
	{
		rd = read(fd, &buff, 100);
		if (read < 0)
			return (NULL);
		buff[rd] = '\0';
		ptr = str;
		str = ft_strjoin(str, buff);
		if (str == NULL)
			return (free(ptr), NULL);
		ft_free(&ptr);
	}
	close(fd);
	return (str);
}
