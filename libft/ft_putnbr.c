/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:36:54 by framel            #+#    #+#             */
/*   Updated: 2015/12/03 00:35:11 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	tmp;
	int				size;
	int				sign;

	size = 1;
	sign = 1;
	if (n < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	tmp = n * sign;
	while (tmp > 9)
	{
		tmp /= 10;
		size *= 10;
	}
	tmp = n * sign;
	while (size)
	{
		ft_putchar(tmp / size + 48);
		tmp %= size;
		size /= 10;
	}
}
