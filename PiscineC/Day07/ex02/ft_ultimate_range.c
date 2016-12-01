/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 23:45:15 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/02 23:45:46 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int a;

	a = 0;
	if (min >= max)
	{
		return (0);
	}
	if ((range[0] = (int *)malloc(sizeof(int) * (max - min))) == NULL)
	{
		return (0);
	}
	while (min < max)
	{
		range[0][a] = min;
		a++;
		min++;
	}
	return (a);
}
