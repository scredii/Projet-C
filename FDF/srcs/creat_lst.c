/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:03:28 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/31 12:17:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_lstmap	*creat_elem(t_database **info_map, int x)
{
	t_lstmap *tmp;

	if (!(tmp = (t_lstmap*)malloc(sizeof(t_lstmap))))
		return (NULL);
	tmp->y = (*info_map)->window->y_max;
	tmp->x = x;
	tmp->next = NULL;
	return (tmp);
}

static int		fill_lst(char *tmp, t_lstmap **cpy, int a, int b)
{
	char	*color;
	char	*colortmp;

	while (tmp[++a] != ' ' && tmp[a] && tmp[a] != ',')
		if ((!ft_isdigit(tmp[a])) && tmp[a] != '+' && tmp[a] != '-')
			return (0);
	(*cpy)->z = ft_atoi(tmp);
	b = a;
	if (tmp[a] == ',')
	{
		b += 9;
		colortmp = ft_strsub(tmp, a + 3, 6);
		a = -1;
		while (colortmp[++a])
			if (!(ft_ishexa(colortmp[a])))
				return (0);
		if (!(color = ft_convert_base(colortmp, HEXA, DECI)))
			return (0);
		(*cpy)->color = ft_atoi(color);
		free(color);
		free(colortmp);
	}
	else
		(*cpy)->color = 0;
	return (b);
}

static int		get_info(t_database **info_map, char *map, int b, int x)
{
	t_lstmap *cpy;

	if (!((*info_map)->lst))
	{
		(*info_map)->lst = creat_elem(info_map, x);
		cpy = (*info_map)->lst;
	}
	else
	{
		cpy = (*info_map)->lst;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = creat_elem(info_map, x);
		cpy = cpy->next;
	}
	if (!(b += fill_lst(map + b, &cpy, -1, 0)))
		return (-1);
	return (b);
}

static int	get_lst(t_database **info_map, int fd, char *buff, int ret)
{
	int b;
	int x;

	while (ret > 0)
	{
		b = 0;
		x = -1;
		if (ft_count_word_line(buff, ' ') != (*info_map)->window->x_max)
			return (0);
		while (buff[b])
		{
			if (buff[b] != ' ')
			{
				if ((b = get_info(info_map, buff, b, ++x)) == -1)
					return (0);
			}
			else
				b++;
		}
		(*info_map)->window->y_max++;
		free(buff);
		ret = get_next_line(fd, &buff);
	}
	return ((ret == -1) ? 0 : 1);
}

int		creat_lst(t_database **info_map, char *av)
{
	char *buff;
	int fd;
	int ret;

	(*info_map)->window->y_max = 0;
	(*info_map)->lst = NULL;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	ret = get_next_line(fd, &buff);
	if (!((*info_map)->window->x_max = ft_count_word_line(buff, ' ')))
		return (0);
	if (!(get_lst(info_map, fd, buff, ret)))
		return (0);
	close(fd);
	return (1);
}
