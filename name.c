/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:13:03 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 21:14:26 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				get_index(char *name, char **tab)
{
	size_t i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (!ft_strcmp(name, tab[i]))
				return (i);
			i++;
		}
	}
	return (i);
}

static void		name_cpy(char *name, char **line, size_t len)
{
	size_t i;

	i = 0;
	while (len--)
		name[i++] = *(*line)++;
	name[i] = 0;
}

static size_t	word_len(char *line, char stop)
{
	size_t len;

	len = 0;
	if (line)
		while (line[len] && line[len] != stop)
			len++;
	return (len);
}

char			*get_name(char **line, char stop)
{
	char	*name;
	size_t	len;

	name = NULL;
	len = word_len(*line, stop);
	if ((name = (char *)malloc(sizeof(char) * len + 1)))
		name_cpy(name, line, len);
	return (name);
}

int				save_name(char **line, size_t *input, t_map *map)
{
	char *name;

	name = get_name(line, ' ');
	if (name == NULL)
		return (-1);
	map->room = ft_stabuff(map->room, name, input[2]);
	if (map->room == NULL)
		return (-1);
	if (input[0] & SETIN)
		swap_name(map->room, 0, input[2]);
	if (input[0] & SETOUT)
		swap_name(map->room, 1, input[2]);
	map->room[input[2] + 1] = NULL;
	return (0);
}
