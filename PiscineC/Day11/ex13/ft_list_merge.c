/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:50:46 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/27 02:14:12 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *list;

	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list = (*begin_list1);
	while (list->next)
	{
		list = list->next;
	}
	list->next = begin_list2;
}
