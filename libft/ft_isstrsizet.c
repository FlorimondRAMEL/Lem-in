/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrsizet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:43:08 by framel            #+#    #+#             */
/*   Updated: 2016/11/20 21:52:23 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isoversizet(char *nb, int i, int j)
{
	if (i > 20)
		return (1);
	if (nb[j] < OVERSIZET(i))
		return (0);
	return (ft_isoversizet(nb, ++i, ++j));
}

int			ft_isstrsizet(char *nb)
{
	int i;
	int j;
	int len;

	i = 0;
	len = 0;
	if (!ft_isdigit(*nb))
		return (0);
	while (nb[i] == '0')
		i++;
	j = i;
	while (ft_isdigit(nb[i]))
	{
		len++;
		i++;
	}
	if (nb[i])
		return (0);
	if (len > 20)
		return (0);
	if (len < 20)
		return (1);
	if (ft_isoversizet(nb, 0, j))
		return (0);
	return (1);
}
