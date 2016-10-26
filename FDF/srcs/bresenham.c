/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 14:14:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/26 20:01:13 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	write_data_pixel(t_data *info_map)
{
	unsigned int r;
	unsigned int g;
	unsigned int b;

	b = (info_map->colortmp & 0xFF0000) >> 16;
	g = (info_map->colortmp & 0xFF00) >> 8;
	r = (info_map->colortmp & 0xFF);
	if (info_map->x1 >= 0 && info_map->y1 >= 0 && info_map->x1 <= info_map->width && info_map->y1 <= info_map->height)
	{
		info_map->data[info_map->y1 * info_map->size_line + info_map->x1 * (info_map->bpp / 8)] = r;
		info_map->data[info_map->y1 * info_map->size_line + info_map->x1 * (info_map->bpp / 8) + 1] = g;
		info_map->data[info_map->y1 * info_map->size_line + info_map->x1 * (info_map->bpp / 8) + 2] = b;
	}
}


void bressenham(t_data *info_map)
{
	int w = info_map->x2 - info_map->x1 ;
	int h = info_map->y2 - info_map->y1 ;
	int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0 ;
	if (w<0) dx1 = -1 ; else if (w>0) dx1 = 1 ;
	if (h<0) dy1 = -1 ; else if (h>0) dy1 = 1 ;
	if (w<0) dx2 = -1 ; else if (w>0) dx2 = 1 ;
	int longest = abs(w) ;
	int shortest = abs(h) ;
	if (!(longest>shortest))
	{
		longest = abs(h) ;
		shortest = abs(w) ;
		if (h<0) dy2 = -1 ; else if (h>0) dy2 = 1 ;
		dx2 = 0 ;
	}
	int numerator = longest >> 1 ;
	for (int i=0;i<=longest;i++)
	{
		write_data_pixel(info_map);
		numerator += shortest ;
		if (!(numerator<longest))
		{
			numerator -= longest ;
			info_map->x1 += dx1 ;
			info_map->y1 += dy1 ;
		}
		else
		{
			info_map->x1 += dx2 ;
			info_map->y1 += dy2 ;
		}
	}
}

/*void	bresenham_gauchedroite(t_data *info_map)
{
	int i;

	i = -1;
	while (++i <= info_map->cpy_ex)
	{
		write_data_pixel(info_map);
		info_map->x1 += info_map->xincr;
		info_map->ex -= info_map->dy;
		if (info_map->ex < 0)
		{
			info_map->y1 += info_map->yincr;
			info_map->ex += info_map->cpy_ex;
//			write_data_pixel(info_map);
		}
	}
}

void	bresenham_hautbas(t_data *info_map)
{
	int i;

	i = -1;
	while (++i <= info_map->cpy_ey)
	{
		write_data_pixel(info_map);
		info_map->y1 += info_map->yincr;
		info_map->ey -= info_map->dx;
		if (info_map->ey < 0)
		{
			info_map->x1 += info_map->xincr;
			info_map->ey += info_map->cpy_ey;
			write_data_pixel(info_map);
		}
	}
	}*/

void	launch_algo(t_data *info_map)
{
	bressenham(info_map);
/*
	info_map->ex = abs(info_map->x2 - info_map->x1);
	info_map->ey = abs(info_map->y2 - info_map->y1);
	info_map->dx = 2 * info_map->ex;
	info_map->dy = 2 * info_map->ey;
	info_map->cpy_ex = info_map->ex;
	info_map->cpy_ey = info_map->ey;
	info_map->xincr = (info_map->x1 > info_map->x2) ? -1 : 1;
	info_map->yincr = (info_map->y1 > info_map->y2) ? -1 : 1;
	if (info_map->cpy_ex >= info_map->cpy_ey)
		bresenham_gauchedroite(info_map);
	else if (info_map->cpy_ex <= info_map->cpy_ey)
		bresenham_hautbas(info_map);
*/
}

int fdf(t_data *info_map)
{
	t_lstmap *cpy1;
	t_lstmap *cpy2;

	info_map->colortmp = 0xFFFFFF;
	cpy1 = info_map->lst;
	cpy2 = info_map->lst;
	while (cpy1->next)
	{
		if (cpy1->y == cpy1->next->y)
		{
			info_map->x1 = (info_map->zoom * ((cpy1->x * cos(info_map->degree)) - (cpy1->y * sin(info_map->degree))) + (info_map->width / 2 + info_map->modif_width));
			info_map->y1 = (info_map->zoom * (((info_map->inclination * (cpy1->x * sin(info_map->degree))) + (info_map->inclination * (cpy1->y * cos(info_map->degree)))) - (cpy1->z * info_map->modif_z)) + (info_map->height / 4 + info_map->modif_height));
			info_map->x2 = (info_map->zoom * ((cpy1->next->x * cos(info_map->degree)) - (cpy1->next->y * sin(info_map->degree))) + (info_map->width / 2 + info_map->modif_width));
			info_map->y2 = (info_map->zoom * (((info_map->inclination * (cpy1->next->x * sin(info_map->degree))) + (info_map->inclination * (cpy1->next->y * cos(info_map->degree)))) - (cpy1->next->z * info_map->modif_z)) + (info_map->height / 4 + info_map->modif_height));
			launch_algo(info_map);
		}
		cpy1 = cpy1->next;
	}
	cpy1 = info_map->lst;
	while (cpy2->y != cpy1->y + 1)
		cpy2 = cpy2->next;
	while (cpy2)
	{
		info_map->x1 = (info_map->zoom * ((cpy1->x * cos(info_map->degree)) - (cpy1->y * sin(info_map->degree))) + (info_map->width / 2 + info_map->modif_width));
		info_map->y1 = (info_map->zoom * (((info_map->inclination * (cpy1->x * sin(info_map->degree))) + (info_map->inclination * (cpy1->y * cos(info_map->degree)))) - (cpy1->z * info_map->modif_z)) + (info_map->height / 4 + info_map->modif_height));
		info_map->x2 = (info_map->zoom * ((cpy2->x * cos(info_map->degree)) - (cpy2->y * sin(info_map->degree))) + (info_map->width / 2 + info_map->modif_width));
		info_map->y2 = (info_map->zoom * (((info_map->inclination * (cpy2->x * sin(info_map->degree))) + (info_map->inclination * (cpy2->y * cos(info_map->degree)))) - (cpy2->z * info_map->modif_z)) + (info_map->height / 4 + info_map->modif_height));
		launch_algo(info_map);
		cpy1 = cpy1->next;
		cpy2 = cpy2->next;
	}
	mlx_put_image_to_window(info_map->mlx, info_map->mlx_window, info_map->image, 0, 0);
	return (1);
}

void	new_screen(t_data *info_map)
{
	mlx_destroy_image(info_map->mlx, info_map->image);
	info_map->image = mlx_new_image(info_map->mlx, info_map->width, info_map->height);
	info_map->data = mlx_get_data_addr(info_map->image, &info_map->bpp, &info_map->size_line, &info_map->endian);
}

int	key_fonc(int key_code, t_data *info_map)
{
	new_screen(info_map);
	printf("%d\n", key_code);
	if (key_code == 53)
		exit(0);
	if (key_code == 0)
	{
		info_map->modif_width -= 3;
	}
	if (key_code == 13)
	{
		info_map->modif_height -= 3;
	}
	if (key_code == 2)
	{
		info_map->modif_width += 3;
	}
	if (key_code == 1)
	{
		info_map->modif_height += 3;
	}
	if (key_code == 6)
	{
		info_map->degree -= 0.1;
	}
	if (key_code == 7)
	{
		info_map->degree += 0.1;
	}
	if (key_code == 15)
	{
		info_map->modif_z += 0.1;
	}
	if (key_code == 3)
	{
		info_map->modif_z -= 0.1;
	}
	if (key_code == 12)
	{
		info_map->zoom -= (info_map->zoom == 0) ? 0 : 1;
	}
	if (key_code == 14)
	{
		info_map->zoom += 1;
	}
	if (key_code == 8)
	{
		info_map->inclination -= 0.1;
	}
	if (key_code == 9)
	{
		info_map->inclination += 0.1;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data *info_map;

	if (!(info_map = creat_tab(av[1])))
		return (0);
	mlx_loop_hook(info_map->mlx, fdf, info_map);
	mlx_hook(info_map->mlx_window, KeyPress, KeyPressMask, key_fonc, info_map);
	mlx_loop(info_map->mlx);
	return (0);
}
