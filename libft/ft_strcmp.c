/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:59:51 by framel            #+#    #+#             */
/*   Updated: 2015/12/09 15:33:48 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int a;
	int i;

	i = 0;
	a = ft_strlen(s1) - ft_strlen(s2);
	if (a == 0)
	{
		while (s1[i] != '\0')
		{
			a = (s1[i] - s2[i]);
			if (a)
				return (a);
			i++;
		}
	}
	return (a);
}
