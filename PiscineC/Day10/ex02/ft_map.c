/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:36:14 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/15 23:35:14 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int a;
	int *tab_mod;

	a = 0;
	if ((tab_mod = (int*)malloc(sizeof(int) * length)) == NULL)
		return (0);
	while (a < length)
	{
		tab_mod[a] = f(tab[a]);
		a++;
	}
	return (tab_mod);
}
