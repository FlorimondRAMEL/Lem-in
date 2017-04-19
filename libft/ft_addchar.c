/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 04:35:17 by framel            #+#    #+#             */
/*   Updated: 2016/11/06 05:52:10 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_addchar(char const *s1, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (s1)
	{
		str = malloc(ft_strlen(s1) + 2);
		if (str == NULL)
			return (NULL);
		while (*s1)
			str[i++] = *s1++;
		str[i++] = c;
		str[i] = '\0';
		return (str);
	}
	return (0);
}
