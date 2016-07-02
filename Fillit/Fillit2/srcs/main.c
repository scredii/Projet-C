/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:31:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/14 11:38:22 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_fillit *fillit;

	if (ac < 2)
		ft_putstr("usage : FILE MISSING\n");
	else if (ac > 2)
		ft_putstr("usage : TOO MUCH FILES\n");
	else
	{
		if (!(fillit = (t_fillit*)malloc(sizeof(t_fillit))))
			return (0);
		if (!(map_check(av[1], fillit)))
		{
			ft_putstr("error\n");
			return (0);
		}
		ft_resolve(fillit);
	}
	return (0);
}
