/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:48 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 19:32:20 by ddufour          ###   ########.fr       */
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

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*list;
	int		a;

	if (!(*begin_list))
		return ;
	a = 1;
	while (a)
	{
		a = 0;
		list = *begin_list;
		while (list->next)
		{
			if ((*cmp)(list->data, list->next->data) > 0)
			{
				ft_swap(&list->data, &list->next->data);
				a = 1;
			}
			list = list->next;
		}
	}
}
