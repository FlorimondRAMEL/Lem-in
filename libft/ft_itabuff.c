/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itabuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:41:44 by framel            #+#    #+#             */
/*   Updated: 2016/11/18 15:55:51 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	**ft_itabuff(size_t **tab, size_t *line, size_t index)
{
	size_t	i;
	size_t	**tmp;

	i = 0;
	if (index % BUFF_SIZE == 0)
	{
		tmp = (size_t **)malloc(BUFF_SIZE * sizeof(size_t *) \
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
