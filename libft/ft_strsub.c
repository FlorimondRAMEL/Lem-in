/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:12:48 by framel            #+#    #+#             */
/*   Updated: 2016/04/14 00:38:18 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;

	if (s)
	{
		str = (char*)malloc(len + 1);
		tmp = str;
		if (str == NULL || tmp == NULL)
			return (NULL);
		while (len-- && *s != '\0')
		{
			*str++ = *(s++ + start);
			*str = '\0';
		}
		return (tmp);
	}
	return (0);
}
