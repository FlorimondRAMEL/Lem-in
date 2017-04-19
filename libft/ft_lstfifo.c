/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfifo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:01:22 by framel            #+#    #+#             */
/*   Updated: 2016/10/17 21:29:47 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfifo(t_list **lst, const void *data, size_t size)
{
	t_list *tmp;

	tmp = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = ft_lstnew(data, size);
	*lst = tmp;
}
