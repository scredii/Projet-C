/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 23:35:54 by ddufour           #+#    #+#             */
/*   Updated: 2016/05/24 14:37:35 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int ac, char **av)
{
	char	**map;
	int		a;

	a = 0;
	map = NULL;
	if (ac == 1)
	{
		if ((map = valid_map(NULL, 0, map)) == NULL)
			return (0);
		map_resolve(map, 0, 0, 0);
	}
	else
		while (++a < ac)
			if ((map = valid_map(av[a], 1, map)) == NULL)
			{
				write(1, "map error\n", 10);
				if (a + 1 == ac)
					return (0);
			}
			else
				map_resolve(map, 0, 0, 0);
	return (0);
}
