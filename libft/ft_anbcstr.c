/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anbcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 05:29:29 by framel            #+#    #+#             */
/*   Updated: 2016/04/14 06:24:04 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_anbcstr(char a, int n, char b, char c)
{
	int		i;
	char	*str;

	i = 0;
	if (n < 0)
		n = 0;
	str = NULL;
	if ((str = (char*)malloc(sizeof(char) * n + 3)) == NULL)
		return (NULL);
	str[i++] = a;
	while (n--)
		str[i++] = b;
	str[i++] = c;
	str[i] = 0;
	return (str);
}
