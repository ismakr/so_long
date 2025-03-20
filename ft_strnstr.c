/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isakrout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 22:21:04 by isakrout          #+#    #+#             */
/*   Updated: 2025/03/19 17:07:28 by isakrout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
			ret = i;
		while (big[i + j] == little[j] && big[i + j] && little[j]
			&& i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)&big[ret]);
		i++;
	}
	return (0);
}
