/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:03:28 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/26 19:54:04 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_lstmap	*creat_elem(t_data **data, int x)
{
	t_lstmap *tmp;

	if (!(tmp = (t_lstmap*)malloc(sizeof(t_lstmap))))
		return (NULL);
	tmp->y = (*data)->y_max;
	tmp->x = x;
	tmp->next = NULL;
	return (tmp);
}

static int		fill_lst(char *tmp, t_lstmap **cpy)
{
	int		a;
	char	*color;
	char	*colortmp;

	a = -1;
	while (tmp[++a] != ' ' && tmp[a] && tmp[a] != ',')
		if ((!ft_isdigit(tmp[a])) && tmp[a] != '+' && tmp[a] != '-')
			return (0);
	(*cpy)->z = ft_atoi(tmp);
	if (tmp[a] == ',')
	{
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
	return (1);
}

static int		info_map(t_data **data, char *map, int b, int x)
{
	t_lstmap *cpy;

	if (!((*data)->lst))
	{
		(*data)->lst = creat_elem(data, x);
		cpy = (*data)->lst;
	}
	else
	{
		cpy = (*data)->lst;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = creat_elem(data, x);
		cpy = cpy->next;
	}
	if (!(fill_lst(map + b, &cpy)))
		return (-1);
	while (map[b] != ' ' && map[b])
		b++;
	return (b);
}

static int		creat_lst(t_data **data, char **map, int a)
{
	int b;
	int x;

	(*data)->y_max = 0;
	(*data)->lst = NULL;
	while (map[++a])
	{
		b = 0;
		x = 0;
		if (ft_count_word_line(map[a], ' ') != (*data)->x_max)
			return (0);
		while (map[a][b])
		{
			if (map[a][b] != ' ')
			{
				if ((b = info_map(data, map[a], b, x)) == -1)
					return (0);
				x++;
			}
			else
				b++;
		}
		(*data)->y_max++;
	}
	return (1);
}

void	ft_list_reverse(t_lstmap **begin_list)
{
	t_lstmap *list;
	t_lstmap *tmp;
	t_lstmap *tmp2;

	tmp = 0;
	list = *begin_list;
	if (!list || (!list->next))
		return ;
	tmp = list->next;
	tmp2 = tmp->next;
	list->next = 0;
	tmp->next = list;
	while (tmp2)
	{
		list = tmp;
		tmp = tmp2;
		tmp2 = tmp2->next;
		tmp->next = list;
	}
	*begin_list = tmp;
}
void	inital_position(t_data *info_map)
{
	info_map->modif_width = 0;
	info_map->modif_height = 0;
	info_map->zoom = 15;
	info_map->modif_z = 0.1;
	info_map->degree = 1;
	info_map->inclination = 1;
}

t_data			*creat_tab(char *av)
{
	t_data	*data;
	char	**map;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->data = ft_get_map(av)))
		return (NULL);
	if (!(map = ft_strsplit(data->data, '\n')))
		return (NULL);
	free(data->data);
	if (!(data->x_max = ft_count_word_line(map[0], ' ')))
		return (NULL);
	if (!(creat_lst(&data, map, -1)))
		return (NULL);
	ft_free_tab(&map);
	data->width = (data->x_max * 100 < 1100) ? data->x_max * 100 : 1100;
	data->height = (data->x_max * 100 < 750) ? data->x_max * 100 : 750;
	data->bpp = 24;
	data->size_line = data->width * (data->bpp / 8);
	data->endian = 1;
	inital_position(data);
	data->mlx = mlx_init();
	data->mlx_window = mlx_new_window(data->mlx, data->width, data->height, av);
	data->image = mlx_new_image(data->mlx, data->width, data->height);
	data->data = mlx_get_data_addr(data->image, &data->bpp, &data->size_line, &data->endian);
	return (data);
}
