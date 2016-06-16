/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 20:29:53 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 03:41:30 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list_ptr;
	t_list *tmp;

	while (*begin_list && !((*cmp)((*begin_list)->data, data_ref)))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	list_ptr = *begin_list;
	while (list_ptr && list_ptr->next)
	{
		if (!(*cmp)(list_ptr->next->data, data_ref))
		{
			tmp = list_ptr->next;
			list_ptr->next = tmp->next;
			free(tmp);
		}
		else if (list_ptr->next)
			list_ptr = list_ptr->next;
	}
}
