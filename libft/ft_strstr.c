/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:00:29 by framel            #+#    #+#             */
/*   Updated: 2015/11/26 19:05:53 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int size;
	int i;
	int j;

	i = 0;
	j = 0;
	size = 0;
	while (s2[size] != '\0')
		size++;
	if (size == 0)
		return ((char*)s1);
	while (s1[j] != '\0')
	{
		while (s2[i] == s1[i + j])
		{
			if (i == size - 1)
				return ((char*)(s1 + j));
			else
				i++;
		}
		i = 0;
		j++;
	}
	return (NULL);
}
