/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 05:41:16 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 21:46:43 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static size_t	get_tube(size_t *room_t, size_t nb, size_t *order)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (order[j])
	{
		i = 0;
		while (i < nb)
		{
			if (room_t[i] == order[j])
				return (order[j]);
			i++;
		}
		j++;
	}
	return (0);
}

t_cube			find_path(t_cube graph, size_t *order)
{
	size_t	i;
	size_t	j;
	size_t	room;
	t_cube	path;

	i = graph.ddd;
	j = 1;
	room = 0;
	path.dd = (size_t *)ft_memalloc(sizeof(size_t) * (i + 1));
	while (path.dd[j - 1] != 1)
	{
		path.dd[j] = get_tube(graph.d[room], graph.dd[room], order);
		room = path.dd[j];
		j++;
		i--;
	}
	return (path);
}

static void		print_step(size_t *i, size_t nb, size_t *path, char **room)
{
	ft_putchar('L');
	ft_putnbr(i[0] + 1);
	ft_putchar('-');
	i[0]++;
	if (i[0] == nb)
		ft_putendl(room[path[i[1] - i[0] + 1]]);
	else
	{
		ft_putstr(room[path[i[1] - i[0] + 1]]);
		ft_putchar(' ');
	}
}

void			resolve(size_t ant, size_t *path, char **room)
{
	size_t	i[2];
	size_t	nb;
	size_t	last;

	i[1] = 1;
	nb = 1;
	last = 0;
	while (last < ant)
	{
		while (i[1] <= ant || path[i[1] - i[0] + 1])
		{
			i[0] = last;
			while (i[0] < ant + 0 && i[0] < nb + 0)
			{
				if (path[i[1] - i[0]] || (i[1] - i[0]) == last)
					print_step(i, nb, path, room);
				else
					i[0]++;
			}
			if (nb < ant)
				nb++;
			i[1]++;
		}
		last++;
	}
}
