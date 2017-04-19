/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 03:40:48 by framel            #+#    #+#             */
/*   Updated: 2016/11/30 04:09:57 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap_name(char **tab, size_t a, size_t index)
{
	char *tmp;

	if (a == index)
		return ;
	tmp = tab[a];
	tab[a] = tab[index];
	tab[index] = tmp;
}

void	swap_coord(size_t **tab, size_t a, size_t *input)
{
	size_t tmp;

	if (!a)
	{
		input[0] &= ~SETIN;
		input[0] |= IN;
	}
	else
	{
		input[0] &= ~SETOUT;
		input[0] |= OUT;
	}
	if (a == input[2])
		return ;
	tmp = tab[a][0];
	tab[a][0] = tab[input[2]][0];
	tab[input[2]][0] = tmp;
	tmp = tab[a][1];
	tab[a][1] = tab[input[2]][1];
	tab[input[2]][1] = tmp;
}
