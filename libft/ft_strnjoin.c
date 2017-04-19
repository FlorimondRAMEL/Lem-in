/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:56:16 by framel            #+#    #+#             */
/*   Updated: 2016/10/25 22:10:10 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnjoin(char **line, char *buf, size_t st, size_t len)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(*line) + len + 1))))
		return (-1);
	while ((*line)[i] != 0)
	{
		tmp[i] = (*line)[i];
		i++;
	}
	while (len--)
	{
		tmp[i] = buf[st++];
		i++;
	}
	tmp[i] = 0;
	free(*line);
	*line = tmp;
	return (0);
}
