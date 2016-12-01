/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 09:03:53 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 03:30:24 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							void *data_ref, int (*cmp)())
{
	t_list *list_ptr;

	if (!begin_list)
		return ;
	list_ptr = begin_list;
	while (list_ptr)
	{
		if (((*cmp)(list_ptr->data, data_ref)) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
