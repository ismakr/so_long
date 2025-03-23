/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:15:25 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/22 16:54:38 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = ft_strlen(s) - 1;
	if (j < 0)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (j != 0 && s[j] == c)
		j--;
	while (s[i] && i <= j)
	{
		if (s[i] == c && s[i - 1] != c)
			res += 1;
		i++;
	}
	if (res == 0 && s[i - 1] == c)
		return (res);
	res += 1;
	return (res);
}

static void	ft_fill(char *p, char *s, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
}

static char	**ft_free(char *arr, int j)
{
	j--;
	while (j != 0)
	{
		free(&arr[j]);
		j--;
	}
	free(arr);
	return (NULL);
}

static int	ft_allo(char **arr, int i, char *s, char c)
{
	int	wc;
	int	l;

	l = i;
	wc = 0;
	while (s[l] != c && s[l])
	{
		wc++;
		l++;
	}
	*arr = malloc(wc * sizeof(char) + 1);
	if (arr == NULL)
	{
		return (0);
	}
	ft_fill(*arr, &s[i], wc);
	if (!s[l])
		l--;
	return (l);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**arr;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	arr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			i = ft_allo(&arr[j], i, s, c);
			if (i == 0)
				return (ft_free(arr[j], j));
			j++;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
/*
#include <stdio.h>
int main()
{
	char *s = "abc abc";
	char **p = ft_split(s, ' ');
	if (p == NULL)
	{
		printf("NULL");
		return (0);
	}
	printf("%d\n", count_word(s, ' '));
	int i = 0;
	while (p[i])
	{
		printf("%s\n", p[i]);
		i++;
	}
}*/
