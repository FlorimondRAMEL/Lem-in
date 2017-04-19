/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <framel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 05:24:28 by framel            #+#    #+#             */
/*   Updated: 2016/05/27 16:24:04 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strbuff(const char *s1, char **s2)
{
	int i;
	int j;

	i = 0;
	if (BUFF_SIZE > 0)
	{
		ft_buffalloc(s2);
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
