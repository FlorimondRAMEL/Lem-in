/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:50:23 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 23:27:15 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_invalid(size_t status)
{
	if (status & IN)
		if (status & OUT)
			return (0);
	return (-1);
}
