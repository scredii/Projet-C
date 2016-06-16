/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:34:27 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/18 15:51:57 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_norme(int a, int flag, char *buftmp)
{
	if (a != 16 && a != 0)
	{
		ft_complign(a, flag);
		ft_print_third(buftmp);
	}
	write(1, "\n", 1);
	if (a != 0)
	{
		ft_one(a, flag);
		write(1, "\n", 1);
	}
}

int		ft_normdeux(int a, int flag, char *buftmp)
{
	ft_print_third(buftmp);
	write(1, "\n", 1);
	ft_one(a, flag);
	a = 0;
	return (a);
}

int		ft_normetrois(int a, int flag)
{
	a = 0;
	ft_one(a, flag);
	return (a);
}

void	ft_hexflag(int fd, int b, int ac, int flag)
{
	char		buffer;
	static int	a;
	static char	*buftmp;
	static int	c;

	if (fd == -1)
	{
		if (b == (ac - 1) && a != 0)
			ft_norme(a, flag, buftmp);
		return ;
	}
	c += 1;
	if (c == 1)
		a = ft_normetrois(a, flag);
	while ((read(fd, &buffer, 1)) != 0)
	{
		ft_two(buffer, flag, a);
		a++;
		buftmp = ft_concat(buftmp, buffer, a);
		if (a == 16)
			a = ft_normdeux(a, flag, buftmp);
	}
	if (b == (ac - 1))
		ft_norme(a, flag, buftmp);
}
