/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:23:43 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/16 15:48:38 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		write(1, &str[a], 1);
		a++;
	}
}

void	ft_one(int count, int flag)
{
	static int	a;
	char		*tmps;

	a += count;
	tmps = ft_convert_base(ft_itoa(a), DECI, HEXA);
	firstcaract(tmps, flag);
}

void	ft_two(char buffer, int flag, int a)
{
	char *tmps;

	if (flag == 8)
	{
		if (a == 0 || a == 8)
			write(1, "  ", 2);
		else
			write(1, " ", 1);
		tmps = ft_convert_base(ft_itoa((int)buffer), DECI, HEXA);
		ft_putstr(ft_strtwo(tmps));
	}
	else
	{
		write(1, " ", 1);
		tmps = ft_convert_base(ft_itoa((int)buffer), DECI, HEXA);
		ft_putstr(ft_strtwo(tmps));
	}
}

void	ft_print_third(char *buftmp)
{
	int	a;

	a = 0;
	write(1, "  |", 3);
	while (buftmp[a])
	{
		if (buftmp[a] == '\n' || buftmp[a] == '\t' ||
			buftmp[a] == '\v' || buftmp[a] == '\f' || buftmp[a] == '\r')
			write(1, ".", 1);
		else
			write(1, &buftmp[a], 1);
		a++;
	}
	write(1, "|", 1);
}

void	ft_puterrno(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		write(2, &str[a], 1);
		a++;
	}
}
