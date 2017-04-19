/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:59:37 by framel            #+#    #+#             */
/*   Updated: 2016/10/31 12:55:22 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_read(int fd, t_gnl *get, char **line)
{
	get->ret = read(fd, get->buf, BUFF_SIZE);
	if (get->ret == -1)
	{
		free(*line);
		return (-1);
	}
	get->i = 0;
	return (get->ret);
}

static int	ft_next(int fd, t_gnl *get, char **line)
{
	if (get->ret <= 0)
		get->ret = ft_read(fd, get, line);
	if (get->ret == -1)
		return (-1);
	else if (get->ret == 0 && **line == 0)
	{
		free(*line);
		return (0);
	}
	else if (get->ret == 0)
		return (1);
	get->j = get->i;
	while (get->ret && get->buf[get->i] && get->buf[get->i] != '\n')
	{
		get->i++;
		get->ret--;
	}
	ft_strnjoin(line, get->buf, get->j, (get->i - get->j));
	if (get->buf[get->i] == '\n')
	{
		get->i++;
		get->ret--;
		return (1);
	}
	return (ft_next(fd, get, line));
}

int			ft_gnl(int fd, char **line)
{
	static t_gnl	get;

	if (fd < 0 || line == NULL || !(*line = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	return (ft_next(fd, &get, line));
}
