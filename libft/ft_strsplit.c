/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:54:19 by framel            #+#    #+#             */
/*   Updated: 2016/04/14 00:38:24 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int	w;

	while (*s && *s == c)
		++s;
	if (*s)
		w = 1;
	else
		w = 0;
	while (*++s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			++w;
	}
	return (w);
}

static void		ft_incr(char *s, char *c, int *i, int *start)
{
	while (s[*i] == *c && s[*i] != '\0')
		*i = *i + 1;
	*start = *i;
	while (s[*i] != *c && s[*i] != '\0')
		*i = *i + 1;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	char	*str;
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)s;
	ptr = (char**)malloc(sizeof(*ptr) * (ft_count(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		ft_incr(str, &c, &i, &start);
		if (start == i)
			ptr[j] = NULL;
		else
			ptr[j] = ft_strsub(str, start, i - start);
		j++;
	}
	ptr[ft_count(s, c)] = NULL;
	return (ptr);
}
