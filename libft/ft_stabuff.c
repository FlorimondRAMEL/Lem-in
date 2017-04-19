/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stabuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:42:41 by framel            #+#    #+#             */
/*   Updated: 2016/11/18 15:54:54 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_stabuff(char **tab, char *line, size_t index)
{
	size_t	i;
	char	**tmp;

	i = 0;
	if (index % BUFF_SIZE == 0)
	{
		tmp = (char **)malloc(BUFF_SIZE * sizeof(char *) \
				* (index / BUFF_SIZE + 2));
		if (!tmp)
			return (NULL);
		while (i < index)
		{
			tmp[i] = tab[i];
			i++;
		}
		if (tab)
			free(tab);
		tab = tmp;
	}
	tab[index] = line;
	return (tab);
}
