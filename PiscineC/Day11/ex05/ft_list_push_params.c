/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 17:47:37 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 03:01:15 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*elem;
	t_list	*list;
	int		a;

	a = 0;
	list = 0;
	while (a < ac)
	{
		elem = ft_create_elem(av[a]);
		elem->next = list;
		list = elem;
		a++;
	}
	return (list);
}
