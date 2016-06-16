/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:40:21 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 03:47:49 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list **data1, t_list **data2)
{
	void *tmp;

	tmp = (*data1)->data;
	(*data1)->data = (*data2)->data;
	(*data2)->data = tmp;
}

int		ft_list_size(t_list *begin_list)
{
	int a;

	a = 0;
	while (begin_list)
	{
		a++;
		begin_list = begin_list->next;
	}
	return (a);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int a;

	a = 0;
	while (a < nbr)
	{
		if (!begin_list)
			return (0);
		begin_list = begin_list->next;
		a++;
	}
	return (begin_list);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*elem;
	t_list	*elem2;
	int		list_size;
	int		a;
	int		b;

	list_size = ft_list_size(begin_list);
	a = 0;
	b = list_size - 1;
	while (a < b)
	{
		elem = ft_list_at(begin_list, a);
		elem2 = ft_list_at(begin_list, b);
		ft_swap(&elem, &elem2);
		a++;
		b--;
	}
}
