/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:03:04 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/17 16:34:57 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_search_error(int a, int ac, char **av)
{
	int fd;
	int b;

	b = 0;
	while (a < ac)
	{
		fd = open(av[a], O_RDWR);
		if (fd == -1)
		{
			ft_errno(av[a]);
			b++;
		}
		close(fd);
		a++;
	}
	return (b);
}

int		main(int ac, char **av)
{
	int fd;
	int a;
	int b;

	if (av[1][0] == '-')
		a = 2;
	else
		a = 1;
	b = ft_search_error(a, ac, av);
	if ((b + a) == ac)
		ft_badfile(av[ac - 1]);
	while (a < ac)
	{
		fd = open(av[a], O_RDWR);
		if (av[1][0] == '-')
			ft_hexflag(fd, a, ac, 8);
		else
			ft_hexnoflag(fd, a, ac, 7);
		close(fd);
		a++;
	}
	return (0);
}
