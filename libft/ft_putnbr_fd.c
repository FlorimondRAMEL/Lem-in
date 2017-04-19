/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:47:43 by framel            #+#    #+#             */
/*   Updated: 2015/12/03 00:33:22 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;
	int				size;
	int				sign;

	size = 1;
	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	tmp = n * sign;
	while (tmp > 9)
	{
		size *= 10;
		tmp /= 10;
	}
	tmp = n * sign;
	while (size)
	{
		ft_putchar_fd(tmp / size + 48, fd);
		tmp %= size;
		size /= 10;
	}
}
