/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:26:58 by framel            #+#    #+#             */
/*   Updated: 2016/04/14 00:37:01 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cpy(char const *s, char *str, int i, int t)
{
	int e;

	e = 0;
	while (t != i)
	{
		str[e] = s[i];
		e++;
		i++;
	}
	str[e] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		t;
	char	*str;

	i = 0;
	if (s)
	{
		t = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == t)
		{
			str = (char*)malloc(sizeof(char));
			return (ft_cpy(s, str, i, t));
		}
		while (s[t - 1] == ' ' || s[t - 1] == '\n' || s[t - 1] == '\t')
			t--;
		str = (char*)malloc(sizeof(char) * (t - i + 1));
		if (str == NULL)
			return (NULL);
		return (ft_cpy(s, str, i, t));
	}
	return (0);
}
