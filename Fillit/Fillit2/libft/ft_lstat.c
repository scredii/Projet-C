/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 19:02:56 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/09 20:01:42 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list **list, unsigned int n)
{
	t_list			*buf;
	unsigned int	i;

	i = 0;
	buf = *list;
	if (!list)
		return (NULL);
	while (i < n)
		buf = buf->next;
	return (buf);
}
