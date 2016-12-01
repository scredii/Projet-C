/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:02:24 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 19:28:46 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list1;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list1 = (*begin_list1);
	while (list1->next)
		list1 = list1->next;
	list1->next = begin_list2;
}

void	ft_swap(void **data1, void **data2)
{
	void *tmp;

	tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}

void	ft_sorted_list_merge(t_list **begin_list1,
								t_list *begin_list2, int (*cmp)())
{
	t_list	*list2;
	int		a;

	if (!(*begin_list1) && !begin_list2)
		return ;
	list_merge(begin_list1, begin_list2);
	a = 1;
	while (a)
	{
		a = 0;
		list2 = (*begin_list1);
		while (list2->next)
		{
			if (cmp(list2->data, list2->next->data) > 0)
			{
				ft_swap(&list2->data, &list2->next->data);
				a = 1;
			}
			list2 = list2->next;
		}
	}
}
