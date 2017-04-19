/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffrealloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:18:38 by framel            #+#    #+#             */
/*   Updated: 2016/05/27 16:30:12 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_buffrealloc(char **s)
{
	char *tmp1;
	char *tmp2;

	tmp1 = *s;
	ft_buffalloc(&tmp2);
	*s = ft_strjoin(*s, tmp2);
	free(tmp1);
	free(tmp2);
}
