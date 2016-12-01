/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:49:33 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/17 16:11:47 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	normalacon(char *nbr, char *operateur, char *nbr2)
{
	void (*onction[5])(int, int);

	onction[0] = &addition;
	onction[1] = &soustraction;
	onction[2] = &multiplication;
	onction[3] = &division;
	onction[4] = &modulo;
	if (operateur[0] == '+')
		onction[0](ft_atoi(nbr), ft_atoi(nbr2));
	else if (operateur[0] == '-')
		onction[1](ft_atoi(nbr), ft_atoi(nbr2));
	else if (operateur[0] == '/')
		onction[3](ft_atoi(nbr), ft_atoi(nbr2));
	else if (operateur[0] == '*')
		onction[2](ft_atoi(nbr), ft_atoi(nbr2));
	else if (operateur[0] == '%')
		onction[4](ft_atoi(nbr), ft_atoi(nbr2));
	else
		write(1, "0", 1);
}

void	do_op(char *nbr, char *operateur, char *nbr2)
{
	int a;

	a = 0;
	while (operateur[a])
	{
		if (a == 1)
		{
			write(1, "0", 1);
			return ;
		}
		a++;
	}
	normalacon(nbr, operateur, nbr2);
}
