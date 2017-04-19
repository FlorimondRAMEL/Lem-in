/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:10:38 by framel            #+#    #+#             */
/*   Updated: 2016/12/07 10:49:25 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static int		save_line(char *line, size_t *input, t_map *map)
{
	if (is_cmd(line))
		input[0] |= save_cmd(line, input[0]);
	else if (input[1] && is_room(line))
		input[0] |= save_room(line, input, map);
	else if (!(input[0] & OFF) && is_tube(line, input[0]))
		input[0] |= save_tube(line, input, map);
	else if (!input[1] && ft_isstrsizet(line))
	{
		input[1] = ft_atosizet(line);
		if (input[1] == 0)
			input[0] = OFF + NOANT;
	}
	else
		return (-1);
	return (0);
}

static int		read_file(char **tab, int stat)
{
	int	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
	{
		if (!stat)
			ft_putendl(tab[i]);
		free(tab[i]);
		i++;
	}
	*tab = NULL;
	free(tab);
	return (stat);
}

static char		**ft_gnt(int fd, t_lemin *lemin)
{
	size_t	i;
	char	*line;
	char	**tab;

	i = 0;
	line = NULL;
	tab = NULL;
	while ((ft_gnl(fd, &line)) == 1)
	{
		if (save_line(line, lemin->input, &lemin->map) || (lemin->input[0] & 1))
			return (tab);
		tab = ft_stabuff(tab, line, i++);
	}
	if (tab)
		tab[i] = NULL;
	return (tab);
}

static int		open_file(int argc, char **argv, int *fd)
{
	if (argc > 2)
	{
		argv[0] = argv[0] + 2;
		ft_putstr(argv[0]);
		ft_putendl(": One file at time.");
		return (-1);
	}
	else if (argc == 2)
		*fd = open(argv[1], O_RDONLY);
	else
		*fd = 0;
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_lemin	lemin;

	if (open_file(argc, argv, &fd))
		return (-1);
	ft_memset(&lemin, 0, sizeof(t_lemin));
	if (!(lemin.file = ft_gnt(fd, &lemin)) || is_invalid(lemin.input[0]))
		return (ft_error("ERROR\n"));
	lemin.graph.ddd = lemin.input[2];
	lemin.graph.dd = count_link(lemin.map.tube, lemin.input[2]);
	lemin.graph.d = set_graph(lemin.graph, lemin.map.tube);
	lemin.o_room = browse_graph(lemin.graph, 1, lemin.input);
	if (!(lemin.input[0] & PATH))
		if (read_file(lemin.file, -1))
			return (ft_error("ERROR\n"));
	if (!(lemin.input[0] & PATH))
		return (ft_error("ERROR\n"));
	lemin.path = find_path(lemin.graph, lemin.o_room);
	if (read_file(lemin.file, 0))
		return (ft_error("ERROR\n"));
	ft_putchar('\n');
	resolve(lemin.input[1], lemin.path.dd, lemin.map.room);
	return (0);
}
