/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:26:27 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/19 17:07:51 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < start && *s != '\0')
	{
		s++;
		i++;
	}
	if (ft_strlen(s) < len)
	{
		str = malloc(ft_strlen(s) + 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy((char *)str, s, ft_strlen(s) + 1);
		return (str);
	}
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy((char *)str, s, len + 1);
	return (str);
}

char	*ft_create_retbuff(char **remain)
{
	char	*temp;
	char	*new_line;
	int		i;

	i = 0;
	if (ft_strchr(*remain, '\n') == NULL)
	{
		new_line = ft_substr(*remain, 0, ft_strlen(*remain));
		ft_free(remain);
		*remain = NULL;
	}
	else
	{
		while (remain[0][i] != '\n')
			i++;
		i++;
		new_line = ft_substr(*remain, 0, i);
		temp = ft_substr(*remain, i, ft_strlen(*remain));
		ft_free(remain);
		*remain = temp;
	}
	return (new_line);
}

void	ft_free(char **str)
{
	if (*str)
		free(*str);
}

char	*read_buff(int fd, char **remain, char **buff)
{
	int		rd;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	rd = 1;
	while (rd > 0 && ft_strchr(*remain, '\n') == NULL)
	{
		rd = read(fd, *buff, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(remain), NULL);
		buff[0][rd] = '\0';
		*remain = ft_strjoin(*remain, *buff);
		if (*remain == NULL)
			return (ft_free(remain), NULL);
	}
	if (**remain == '\0')
		return (ft_free(remain), NULL);
	return (*remain);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE == 0)
	{
		ft_free(&remain);
		remain = NULL;
		return (NULL);
	}
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	if (remain == NULL)
	{
		remain = malloc(1);
		if (remain == NULL)
			return (ft_free(&buff), NULL);
		*remain = '\0';
	}
	remain = read_buff(fd, &remain, &buff);
	ft_free(&buff);
	if (remain == NULL)
		return (NULL);
	return (ft_create_retbuff(&remain));
}
/*
int main()
{
	//int f = open("ttt.txt", O_RDONLY);
	char *p;
	p = get_next_line(f);
	printf("%s", p);
	printf("%ld\n", ft_strlen(p));
	free(p);
	int i;
	i = 2;
	while (i--)
	{
		p = get_next_line(50);
		printf("%s", p);
		ft_free(&p);
	}
}*/
