/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 11:41:04 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/14 11:41:36 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_deletemap(t_fillit *fillit, char letter)
{
	int	i;
	int	j;

	j = 0;
	while (MAP[j])
	{
		i = 0;
		while (MAP[j][i])
		{
			if (MAP[j][i] == letter)
				MAP[j][i] = '.';
			i++;
		}
		j++;
	}
}

char	ft_checkletter(char *map)
{
	char	letter;
	int		i;

	i = 0;
	while (map[i])
	{
		if (ft_isalpha(map[i]))
			letter = map[i];
		i++;
	}
	return (letter);
}

int		put_tetris_map(t_fillit *fillit, char *tetris, int x, int y)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = x;
	if (check_same_carac(fillit, tetris, x, y))
		while (tetris[++i])
		{
			if (tetris[i] == '.')
				x++;
			if (ft_isalpha(tetris[i]))
			{
				if (MAP[y][x] == '.')
					MAP[y][x++] = tetris[i];
			}
			if (tetris[i] == '\n')
			{
				y++;
				x = tmp;
			}
		}
	else
		return (0);
	return (1);
}

char	**ft_fillit(t_fillit *fillit, char **tetris, int x, int y)
{
	while (!(put_tetris_map(fillit, *tetris, x, y)))
	{
		x++;
		if (x > SIZE - 1)
		{
			y++;
			x = 0;
			if (y > SIZE - 1)
				return (NULL);
		}
	}
	if (*(tetris + 1))
	{
		while (!(ft_fillit(fillit, tetris + 1, 0, 0)))
		{
			ft_deletemap(fillit, ft_checkletter(*tetris));
			return (ft_fillit(fillit, tetris, ++x, y));
		}
	}
	return (MAP);
}

void	ft_resolve(t_fillit *fillit)
{
	int		i;

	i = -1;
	MAP = ft_creat_map(fillit);
	while (((MAP = ft_fillit(fillit, fillit->tetris, 0, 0)) == NULL))
	{
		free(MAP);
		SIZE++;
		MAP = ft_creat_map(fillit);
	}
	while (MAP[++i])
		ft_putstr(MAP[i]);
	ft_free(MAP);
}
