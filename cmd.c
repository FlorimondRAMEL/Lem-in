/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:14:50 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 21:15:06 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	save_cmd(char *line, size_t status)
{
	if (!ft_strcmp(line, "##start"))
	{
		if ((status & SETIN) || (status & IN))
			return (MULTS + OFF);
		else
			return (SETIN);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if ((status & SETOUT) || (status & OUT))
			return (MULTE + OFF);
		else
			return (SETOUT);
	}
	return (0);
}

int	is_cmd(char *line)
{
	if (!ft_strcmp(line, "##start"))
		return (1);
	else if (!ft_strcmp(line, "##end"))
		return (1);
	else if (line[0] == '#')
		return (1);
	return (0);
}
