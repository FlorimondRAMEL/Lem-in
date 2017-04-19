/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <framel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 20:57:43 by framel            #+#    #+#             */
/*   Updated: 2016/09/15 23:00:55 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_line(int len, char *sav, char **line, int z)
{
	int		i;
	char	*tmp;
	char	*strcpy;

	i = 0;
	while (sav[i] && sav[i] != '\n')
		i++;
	if (z == 0)
		(*line) = ft_strdup("");
	if (i)
	{
		tmp = ft_strnew(i);
		ft_strncpy(tmp, sav, i);
		strcpy = *line;
		(*line) = ft_strjoin(*line, tmp);
		strcpy ? free(strcpy) : 0;
		ft_strdel(&tmp);
	}
	i++;
	return (len - i);
}

static int	check_buf(int *n, char **sav, char **line, int *z)
{
	while (*sav)
	{
		*n = check_line(ft_strlen(*sav), *sav, line, *n);
		*z += ft_strlen(*sav);
		if (*n > 0)
		{
			*sav = ft_strdup(*sav + *z - *n);
			return (1);
		}
		else if (*n == 0)
		{
			*sav = NULL;
			return (1);
		}
		*sav = NULL;
		return (0);
	}
	return (0);
}

static int	check_file(int const fd, char **line, char **sav, int z)
{
	int		current;
	int		n;
	char	buf[BUFF_SIZE + 1];

	if ((n = 0) == 0 && check_buf(&n, sav, line, &z))
		return (1);
	while ((current = read(fd, buf, BUFF_SIZE)))
	{
		if ((buf[current] = 0) == 0 && current == -1)
			return (-1);
		n = check_line(current, buf, line, z);
		z += current;
		if (n > 0)
		{
			*sav = ft_strnew(n);
			ft_strncpy(*sav, buf + current - n, n);
		}
		else if (n == 0)
			ft_strdel(sav);
		if (n != -1)
			return (1);
	}
	return (0);
}

int			ft_gnl(int const fd, char **line)
{
	int			ret;
	static char	*sav[256];

	if (fd < 0 || fd > 255 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (line)
		(*line) = NULL;
	if ((ret = check_file(fd, line, &sav[fd], 0)) == -1)
		return (-1);
	else if (ret)
		return (1);
	else if (*line && ft_strlen(*line) > 0 && ret == 0)
		return (1);
	return (0);
}
