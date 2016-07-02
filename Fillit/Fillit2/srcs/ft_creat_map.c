/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:04:42 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/14 11:08:37 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char		**ft_creat_map(t_fillit *fillit)
{
	char	**tet;
	int		i;
	int		j;

	if (!(tet = (char**)malloc(sizeof(char*) * SIZE + 1)))
		return (NULL);
	i = -1;
	while (++i < SIZE)
	{
		tet[i] = ft_strnew(SIZE + 1);
		j = -1;
		while (++j < SIZE)
			tet[i][j] = '.';
		tet[i][SIZE] = '\n';
	}
	tet[SIZE] = 0;
	return (tet);
}

int			check_same_carac(t_fillit *fillit, char *tetris, int x, int y)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = x;
	while (tetris[++i])
	{
		if (ft_isalpha(MAP[y][x]) && ft_isalpha(tetris[i]))
			return (0);
		if (tetris[i] != '\n')
			x++;
		if (x > SIZE)
			return (0);
		if (tetris[i] == '\n')
		{
			y++;
			x = tmp;
			if (y > SIZE - 1)
				return (0);
		}
	}
	return (1);
}
