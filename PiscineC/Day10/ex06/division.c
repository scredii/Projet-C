/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:41:39 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/17 16:11:15 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	division(int a, int b)
{
	int c;

	if (b == 0)
		write(1, "Stop : division by zero", 23);
	else
	{
		c = a / b;
		ft_putnbr(c);
	}
}
