/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:17:20 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/16 15:47:01 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_itoa(int nbr)
{
	char	*str;
	int		nbrcpy;
	int		count;

	nbrcpy = nbr;
	count = 0;
	while (nbrcpy > 0)
	{
		nbrcpy = nbrcpy / 10;
		count++;
	}
	if ((str = (char*)malloc(sizeof(char) * (count + 1))) == NULL)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
