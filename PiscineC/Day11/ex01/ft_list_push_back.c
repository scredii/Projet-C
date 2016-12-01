/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:37:38 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 18:23:52 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *elem;
	t_list *list;

	list = *begin_list;
	elem = ft_create_elem(data);
	if (!(*begin_list))
		*begin_list = elem;
	else
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
}
