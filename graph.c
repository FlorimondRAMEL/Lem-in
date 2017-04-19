/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:08:04 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 22:41:53 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	RW_ORDER
**	[0] = READ
**	[1] = WRITE
*/

size_t	*browse_graph(t_cube gr, size_t room, size_t *input)
{
	size_t	rw_order[2];
	size_t	tube;
	size_t	*ord;

	ft_memset(rw_order, 0, sizeof(rw_order));
	if (((ord = (size_t *)ft_memalloc(sizeof(size_t) * (gr.ddd + 1))) == NULL))
		return (NULL);
	ord[rw_order[1]] = room;
	while (ord[rw_order[0]])
	{
		tube = 0;
		while (tube < gr.dd[room])
		{
			if (!ft_isintab(ord, gr.d[room][tube]))
			{
				rw_order[1]++;
				ord[rw_order[1]] = gr.d[room][tube];
				if (ord[rw_order[1]] == 0)
					input[0] |= PATH;
			}
			tube++;
		}
		room = ord[++rw_order[0]];
	}
	return (ord);
}

size_t	**set_graph(t_cube graph, size_t **tube)
{
	size_t	i;
	size_t	*j;
	size_t	**tab;

	i = -1;
	if (tube == NULL || *tube == NULL)
		return (NULL);
	j = (size_t *)ft_memalloc(sizeof(size_t) * (graph.ddd));
	tab = (size_t **)ft_memalloc(sizeof(size_t *) * (graph.ddd + 1));
	if (tab == NULL || j == NULL)
		return (NULL);
	while (++i < graph.ddd)
		tab[i] = (size_t *)ft_memalloc(sizeof(size_t) * graph.dd[i]);
	i = 0;
	while (tube[i])
	{
		if (tube[i][0] == tube[i][1])
			return (tab);
		tab[tube[i][0]][j[tube[i][0]]] = tube[i][1];
		tab[tube[i][1]][j[tube[i][1]]] = tube[i][0];
		j[tube[i][0]]++;
		j[tube[i][1]]++;
		i++;
	}
	return (tab);
}
