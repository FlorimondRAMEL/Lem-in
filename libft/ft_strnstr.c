/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 01:37:24 by framel            #+#    #+#             */
/*   Updated: 2015/12/08 15:42:18 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_set(size_t *i, int *j, int *tmp)
{
	*i = 0;
	*j = 0;
	*tmp = 0;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		tmp;
	char	*str;

	str = NULL;
	ft_set(&i, &j, &tmp);
	if (s2[0] == 0)
		return ((char*)(s1 + i));
	while (s1[i] && i < n)
	{
		while (s1[i] != s2[j] && s1[i])
			i++;
		str = (char*)(s1 + i);
		while (s1[i] == s2[j] && i < n)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return (str);
		}
		j = 0;
		i = tmp++;
	}
	return (NULL);
}
