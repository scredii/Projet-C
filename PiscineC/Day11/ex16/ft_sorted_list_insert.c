/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:42:43 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/27 04:04:27 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **data1, void **data2)
{
	void *tmp;

	tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*list;
	t_list	*elem;
	int		a;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	(*begin_list) = elem;
	a = 1;
	while (a)
	{
		a = 0;
		list = (*begin_list);
		while (list->next)
		{
			if (cmp(list->data, list->next->data) > 0)
			{
				ft_swap(&list->data, &list->next->data);
				a = 1;
			}
			list = list->next;
		}
	}
}
