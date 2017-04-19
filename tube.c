/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:10:31 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 23:33:06 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t	*count_link(size_t **tube, size_t len)
{
	size_t	*tab;
	int		i;

	i = 0;
	tab = (size_t *)ft_memalloc(sizeof(size_t) * (len));
	if (tab == NULL)
		return (NULL);
	if (tube)
		while (tube[i])
		{
			tab[tube[i][0]]++;
			tab[tube[i][1]]++;
			i++;
		}
	return (tab);
}

int		is_tube(char *line, size_t status)
{
	size_t i;

	i = 0;
	if (!(status & IN) || !(status & OUT))
		return (0);
	if (line[i] == '-')
		return (0);
	while (line[i] && line[i] != '-')
		i++;
	if (line[i] != '-' || line[i + 1] == '\0')
		return (0);
	return (1);
}

int		save_tube(char *line, size_t *input, t_map *map)
{
	size_t	*tube;
	char	*name;

	tube = (size_t *)ft_memalloc(sizeof(size_t) * 2);
	if (tube == NULL)
		return (OFF);
	name = get_name(&line, '-');
	if (name == NULL)
		return (OFF);
	tube[0] = get_index(name, map->room);
	free(name);
	line++;
	name = get_name(&line, '\0');
	if (name == NULL)
		return (OFF);
	tube[1] = get_index(name, map->room);
	free(name);
	if (tube[0] == input[2] || tube[1] == input[2] || tube[0] == tube[1])
		return (OFF);
	map->tube = ft_itabuff(map->tube, tube, input[3]);
	input[3]++;
	map->tube[input[3]] = NULL;
	return (0);
}
