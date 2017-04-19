/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:28:52 by framel            #+#    #+#             */
/*   Updated: 2015/12/07 22:26:18 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = ft_strlen(s);
	while (s[i] != c && i > 0)
		i--;
	if (i == 0 && s[i] != c)
		return (NULL);
	last = (char*)&s[i];
	return (last);
}
