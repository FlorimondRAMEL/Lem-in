/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlifo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:03:05 by framel            #+#    #+#             */
/*   Updated: 2016/10/17 21:29:55 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlifo(t_list **lst, const void *data, size_t size)
{
	t_list *new;

	new = ft_lstnew(data, size);
	new->next = *lst;
	*lst = new;
}
