/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuffend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:20:23 by framel            #+#    #+#             */
/*   Updated: 2016/05/27 16:23:10 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strbuffend(const char *s1, char **s2)
{
	int i;
	int j;

	i = ft_strlen(*s2);
	if (BUFF_SIZE > 0)
	{
		ft_buffrealloc(s2);
		while (*s1)
		{
			j = BUFF_SIZE;
			while (*s1 && j--)
				(*s2)[i++] = *s1++;
			(*s2)[i] = 0;
			if (j < 0)
				ft_buffrealloc(s2);
		}
	}
}
