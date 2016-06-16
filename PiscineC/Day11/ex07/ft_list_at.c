/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:47:49 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 03:23:57 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	a;

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
