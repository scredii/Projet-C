/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 23:42:09 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/04 19:04:59 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int a;

	a = 0;
	if (min >= max)
		return (NULL);
	if ((tab = (int *)malloc(sizeof(int) * (max - min))) == NULL)
	{
		return (NULL);
	}
	while (min < max)
	{
		tab[a] = min;
		a++;
		min++;
	}
	return (tab);
}
