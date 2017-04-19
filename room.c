/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:11:11 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 21:12:37 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_coord(char **line, int xy)
{
	if (xy)
		while (ft_isdigit(**line))
			(*line)++;
	(*line)++;
	return (ft_atoi(*line));
}

int			is_room(char *line)
{
	size_t i;

	i = 0;
	if (line[i] == ' ')
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	if (line[i++] != ' ')
		return (0);
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ' ')
		return (0);
	if (!ft_isdigit(line[i]))
		return (0);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

static int	save_coord(char *line, size_t *input, t_map *map)
{
	size_t *coord;

	coord = (size_t *)malloc(sizeof(size_t) * 2);
	if (coord == NULL)
		return (-1);
	coord[0] = get_coord(&line, 0);
	coord[1] = get_coord(&line, 1);
	map->coord = ft_itabuff(map->coord, coord, input[2]);
	if (map->coord == NULL)
		return (-1);
	if (input[0] & SETIN)
		swap_coord(map->coord, 0, input);
	if (input[0] & SETOUT)
		swap_coord(map->coord, 1, input);
	input[2]++;
	map->coord[input[2]] = NULL;
	return (0);
}

int			save_room(char *line, size_t *input, t_map *map)
{
	if (!input[1] || (input[0] & SETIN && input[0] & IN) || \
			(input[0] & SETOUT && input[0] & OUT))
		return (OFF);
	if (save_name(&line, input, map))
		return (OFF);
	if (save_coord(line, input, map))
		return (OFF);
	return (0);
}
