/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:00:25 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 18:29:10 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int			fdf(t_database *info_map)
{
	t_lstmap *cpy1;
	t_lstmap *cpy2;

	cpy1 = info_map->lst;
	cpy2 = info_map->lst;
	while (cpy1->next)
	{
		if (cpy1->y == cpy1->next->y)
			get_pos(cpy1, cpy1->next, info_map);
		cpy1 = cpy1->next;
	}
	cpy1 = info_map->lst;
	while (cpy2->y != cpy1->y + 1)
		cpy2 = cpy2->next;
	while (cpy2)
	{
		get_pos(cpy1, cpy2, info_map);
		cpy1 = cpy1->next;
		cpy2 = cpy2->next;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (1);
}

static void			new_screen(t_database *info_map, int choice)
{
	if (choice == 1)
	{
		mlx_destroy_image(MLX, IMG);
		IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
		DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	}
	else
	{
		MODW = 0;
		MODH = 0;
		ZOOM = 15;
		MODZ = 0.1;
		DEGREE = 1;
		INCLI = 1;
	}
}

static t_database	*creat_tab(char *av)
{
	t_database	*info_map;

	if (!(info_map = (t_database*)malloc(sizeof(t_database))))
		exit(write(1, "malloc failed\n", 14));
	if (!(info_map->window = (t_param_win*)malloc(sizeof(t_param_win))))
		exit(write(1, "malloc failed\n", 14));
	if (!(info_map->modif_pos = (t_modif_param*)malloc(sizeof(t_modif_param))))
		exit(write(1, "malloc failed\n", 14));
	if (!(creat_lst(&info_map, av)))
		return (NULL);
	WIDTH = (XMAX * 50 < 2400) ? XMAX * 50 : 2400;
	HEIGHT = (YMAX * 50 < 1300) ? YMAX * 50 : 1300;
	BPP = 24;
	SIZELINE = WIDTH * (BPP / 8);
	ENDIAN = 1;
	new_screen(info_map, 0);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, av);
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (info_map);
}

static int			key_fonc(int key_code, t_database *info_map)
{
	new_screen(info_map, 1);
	if (key_code == 53)
		exit(0);
	if (key_code == 48)
		new_screen(info_map, 0);
	if (key_code == 0 || key_code == 2)
		MODW += (key_code == 0) ? -30 : 30;
	if (key_code == 13 || key_code == 1)
		MODH += (key_code == 13) ? -30 : 30;
	if (key_code == 6 || key_code == 7)
		DEGREE += (key_code == 6) ? -0.05 : 0.05;
	if (key_code == 15 || key_code == 3)
		MODZ += (key_code == 15) ? 0.1 : -0.1;
	if (key_code == 12)
		ZOOM -= (ZOOM == 0) ? 0 : 1;
	if (key_code == 14)
		ZOOM += 1;
	if (key_code == 8 || key_code == 9)
		INCLI += (key_code == 8) ? -0.1 : 0.1;
	return (0);
}

int					main(int ac, char **av)
{
	t_database *info_map;

	if (ac != 2)
	{
		ft_putendl("Insert 1 map pls");
		return (0);
	}
	if (!(info_map = creat_tab(av[1])))
	{
		ft_putendl("Map Error");
		return (0);
	}
	mlx_loop_hook(MLX, fdf, info_map);
	mlx_hook(WIN, KeyPress, KeyPressMask, key_fonc, info_map);
	mlx_loop(MLX);
	return (0);
}
