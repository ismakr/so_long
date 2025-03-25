/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <isakrout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:23:33 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/25 00:44:46 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
/*
int main()
{
	int *arr;
	arr = ft_calloc(0, sizeof(int));
	if (arr == NULL)
	{
		printf("NULL\n");
		return 1;
	}
	int i;
	i = 0;
	while (i < 4)
	{
		printf("%d\n", arr[i]);
		i++;
	}
}*/
