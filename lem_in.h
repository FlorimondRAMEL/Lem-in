/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:13:19 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 23:26:34 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

/*
** INPUT[0] = STATUS;
*/

# define ON 0x0
# define OFF 0x1
# define SETIN 0x2
# define IN 0x4
# define SETOUT 0x8
# define OUT 0x10
# define COM 0x20
# define ROOM 0x40
# define TUB 0x80
# define MULTS 0x100
# define MULTE 0x200
# define NOANT 0x400
# define PATH 0x800

typedef struct	s_room
{
	char	*name;
	size_t	xy[2];
}				t_room;

typedef struct	s_cube
{
	size_t ddd;
	size_t *dd;
	size_t **d;
}				t_cube;

/*
**		INPUT[5]
**
**	typedef struct	s_input
**	{
**		[0]size_t	status;
**		[1]size_t	n_ant;
**		[2]size_t	n_room;
**		[3]size_t	n_tube;
**		[4]size_t	index;
*/

typedef struct	s_map
{
	char	**room;
	size_t	**coord;
	size_t	**tube;
}				t_map;

typedef struct	s_lemin
{
	char	**file;
	size_t	input[5];
	t_map	map;
	t_cube	graph;
	size_t	*o_room;
	t_cube	path;
}				t_lemin;

int				is_tube(char *line, size_t status);
int				save_tube(char *line, size_t *input, t_map *map);
int				is_room(char *line);
int				save_room(char *line, size_t *input, t_map *map);
char			*get_name(char **line, char stop);
int				get_index(char *name, char **tab);
int				save_name(char **line, size_t *input, t_map *map);
void			swap_name(char **tab, size_t a, size_t index);
void			swap_coord(size_t **tab, size_t a, size_t *input);
int				is_ant(char *line);
int				save_ant(char *line, size_t *input);
int				save_cmd(char *line, size_t status);
int				is_cmd(char *line);
int				is_ant(char *line);
size_t			*count_link(size_t **tube, size_t len);
size_t			**set_graph(t_cube graph, size_t **tube);
size_t			*browse_graph(t_cube graph, size_t begin, size_t *input);
t_cube			find_path(t_cube graph, size_t *o_room);
void			resolve(size_t ant, size_t *path, char **room);
int				is_invalid(size_t status);

/*
**		DEBUG
**
**void			test_tube(t_map *map);
**void			test_room(t_map *map);
**void			test_coord(t_map *map);
**void			test_graph(t_cube *graph);
**void			test_order(size_t *o_room, size_t nb_room);
**void			test_path(size_t *path);
*/

#endif
