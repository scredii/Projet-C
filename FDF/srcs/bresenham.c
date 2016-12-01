/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:14:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 18:33:33 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	void	get_color(t_database *info_map, float z)
{
	if (COLORTMP == 0)
	{
		if (z > 12)
			COLORTMP = mlx_get_color_value(MLX, 0xCC0033);
		if (z <= 12 && z > 8)
			COLORTMP = mlx_get_color_value(MLX, 0xFF3300);
		if (z <= 8 && z > 6)
			COLORTMP = mlx_get_color_value(MLX, 0xFF3399);
		if (z <= 6 && z > 4)
			COLORTMP = mlx_get_color_value(MLX, 0xFF9933);
		if (z <= 4 && z > 2)
			COLORTMP = mlx_get_color_value(MLX, 0xCCFF66);
		if (z <= 2 && z > 0.1)
			COLORTMP = mlx_get_color_value(MLX, 0x99FF99);
		if (z <= 0.1 && z >= -0.1)
			COLORTMP = mlx_get_color_value(MLX, 0x33CCFF);
		if (z < -0.1 && z >= -4)
			COLORTMP = mlx_get_color_value(MLX, 0x0099FF);
		if (z < -4 && z >= -8)
			COLORTMP = mlx_get_color_value(MLX, 0x0066FF);
		if (z < -8 && z >= -12)
			COLORTMP = mlx_get_color_value(MLX, 0x0033CC);
		if (z < -12)
			COLORTMP = mlx_get_color_value(MLX, 0x000066);
	}
}

static	void	write_data_pixel(t_database *info_map, float z)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	get_color(info_map, z);
	b = (COLORTMP & 0xFF0000) >> 16;
	g = (COLORTMP & 0xFF00) >> 8;
	r = (COLORTMP & 0xFF);
	DATA[Y1 * SIZELINE + X1 * (BPP / 8)] = r;
	DATA[Y1 * SIZELINE + X1 * (BPP / 8) + 1] = g;
	DATA[Y1 * SIZELINE + X1 * (BPP / 8) + 2] = b;
}

static	void	bressenham(t_database *info_map, float z)
{
	int i;

	i = -1;
	while (++i <= LONGEST)
	{
		write_data_pixel(info_map, z);
		NUMERATOR += SHORTEST;
		if (!(NUMERATOR < LONGEST))
		{
			NUMERATOR -= LONGEST;
			X1 += DX1;
			Y1 += DY1;
		}
		else
		{
			X1 += DX2;
			Y1 += DY2;
		}
	}
}

static	void	launch_algo(t_database *info_map, float z)
{
	if (!(info_map->bress = (t_bressenham*)malloc(sizeof(t_bressenham))))
		exit(write(1, "malloc failed\n", 14));
	DX1 = 0;
	DY1 = 0;
	DX2 = 0;
	DY2 = 0;
	DX1 = ((X2 - X1) < 0) ? -1 : 1;
	DY1 = ((Y2 - Y1) < 0) ? -1 : 1;
	DX2 = ((X2 - X1) < 0) ? -1 : 1;
	LONGEST = abs(X2 - X1);
	SHORTEST = abs(Y2 - Y1);
	if (!(LONGEST > SHORTEST))
	{
		LONGEST = abs(Y2 - Y1);
		SHORTEST = abs(X2 - X1);
		DY2 = ((Y2 - Y1) < 0) ? -1 : 1;
		DX2 = 0;
	}
	NUMERATOR = LONGEST >> 1;
	bressenham(info_map, z);
	free(info_map->bress);
}

void			get_pos(t_lstmap *cpy1, t_lstmap *cpy2, t_database *info_map)
{
	if (!(info_map->position = (t_pos_pixel*)malloc(sizeof(t_pos_pixel))))
		exit(write(1, "malloc failed\n", 14));
	X1 = (ZOOM * ((cpy1->x * cos(DEGREE)) - (cpy1->y * sin(DEGREE))) +
			(WIDTH / 2 + MODW));
	Y1 = (ZOOM * (((INCLI * (cpy1->x * sin(DEGREE))) + (INCLI * (cpy1->y *
		cos(DEGREE)))) - (cpy1->z * MODZ)) + (HEIGHT / 4 + MODH));
	X2 = (ZOOM * ((cpy2->x * cos(DEGREE)) - (cpy2->y * sin(DEGREE))) +
			(WIDTH / 2 + MODW));
	Y2 = (ZOOM * (((INCLI * (cpy2->x * sin(DEGREE))) + (INCLI * (cpy2->y *
		cos(DEGREE)))) - (cpy2->z * MODZ)) + (HEIGHT / 4 + MODH));
	COLORTMP = cpy2->color;
	if (X1 > 0 && Y1 > 0 && X1 < WIDTH && Y1 < HEIGHT && X2 > 0 && Y2 > 0 &&
		X2 < WIDTH && Y2 < HEIGHT)
		launch_algo(info_map, ((cpy1->z > cpy2->z) ? cpy1->z : cpy2->z) * MODZ);
	free(info_map->position);
}
