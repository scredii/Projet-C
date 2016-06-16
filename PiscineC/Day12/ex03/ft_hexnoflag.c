/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnoflag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 18:00:27 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/18 15:53:32 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_norm(int a, int flag)
{
	if (a != 16 && a != 0)
		ft_complign(a, flag);
	write(1, "\n", 1);
	if (a != 0)
	{
		ft_one(a, flag);
		write(1, "\n", 1);
	}
}

int		ft_normedeux(int a, int flag)
{
	write(1, "\n", 1);
	ft_one(a, flag);
	a = 0;
	return (a);
}

int		ft_normtrois(int a, int flag)
{
	a = 0;
	ft_one(a, flag);
	return (a);
}

void	ft_hexnoflag(int fd, int b, int ac, int flag)
{
	char		buffer;
	static int	a;
	static int	c;

	if (fd == -1)
	{
		if (b == (ac - 1) && a != 0)
			ft_norm(a, flag);
		return ;
	}
	c += 1;
	if (c == 1)
		a = ft_normtrois(a, flag);
	while ((read(fd, &buffer, 1)) != 0)
	{
		ft_two(buffer, flag, a);
		a++;
		if (a == 16)
			a = ft_normedeux(a, flag);
	}
	if (b == (ac - 1))
		ft_norm(a, flag);
}
