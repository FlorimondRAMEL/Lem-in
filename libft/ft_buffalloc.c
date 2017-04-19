/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:15:09 by framel            #+#    #+#             */
/*   Updated: 2016/05/27 16:28:55 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_buffinit(char **s)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		(*s)[i] = '0';
		i++;
	}
}

void		ft_buffalloc(char **s)
{
	if (!(*s = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return ;
	ft_buffinit(s);
	(*s)[BUFF_SIZE] = 0;
}
