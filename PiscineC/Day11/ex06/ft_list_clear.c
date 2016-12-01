/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:43:22 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/28 06:30:38 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list *list;
	t_list *tmp;

	if (*begin_list)
	{
		list = *begin_list;
		while (list)
		{
			tmp = list->next;
			free(list);
			list = tmp;
		}
		*begin_list = NULL;
	}
}
