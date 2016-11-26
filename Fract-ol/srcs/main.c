/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:48:24 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/25 16:06:32 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static void	write_data_pixel(t_container *fractol, t_thrd *thrd)
{
		DATA[thrd->y * SIZELINE + thrd->x * (BPP / 8)] = (B * thrd->iter) / ITERMAX ;
		DATA[thrd->y * SIZELINE + thrd->x * (BPP / 8) + 1] = (G * thrd->iter) / ITERMAX;
		DATA[thrd->y * SIZELINE + thrd->x * (BPP / 8) + 2] = (R * thrd->iter) / ITERMAX;
}

void	julia(void *arg, void *arg2)
{
	t_container *fractol;
	t_thrd *thrd;

	fractol = arg;
	thrd = arg2;

	thrd->zr = (ANGLES == 0) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->zi = (ANGLES == 1) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->cr = 0.285 + VX;
	thrd->ci = 0.01 + VY;
	thrd->iter = -1;
	while ((thrd->zr * thrd->zr + thrd->zi * thrd->zi < 4) && (++thrd->iter < ITERMAX))
	{
		thrd->tmp = thrd->zr;
		thrd->zr = thrd->zr * thrd->zr - thrd->zi * thrd->zi + thrd->cr;
		thrd->zi = 2 * thrd->zi * thrd->tmp + thrd->ci;
	}
	if (thrd->iter == ITERMAX)
		thrd->iter = 0;
	write_data_pixel(fractol, thrd);
}

void	multijulia(void *arg, void *arg2)
{
	t_container *fractol;
	t_thrd *thrd;

	fractol = arg;
	thrd = arg2;

	thrd->zr = (ANGLES == 0) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->zi = (ANGLES == 1) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->cr = 0.285 + VX;
	thrd->ci = 0.01 + VY;
	thrd->iter = -1;
	while ((thrd->zr * thrd->zr + thrd->zi * thrd->zi < 4) && (++thrd->iter < ITERMAX))
	{
		thrd->tmp = thrd->zr;
		thrd->zr = ((thrd->zr*thrd->zr+thrd->zi*thrd->zi)*((long double)N/2))*(long double)cos((long double)N*(long double)atan2l(thrd->zi,thrd->zr)) + thrd->cr;
		thrd->zi = ((thrd->tmp*thrd->tmp+thrd->zi*thrd->zi)*((long double)N/2))*(long double)sin((long double)N*(long double)atan2l(thrd->zi,thrd->tmp)) + thrd->ci;
	}
	if (thrd->iter == ITERMAX)
		thrd->iter = 0;
	write_data_pixel(fractol, thrd);
}

void	mandelbrot(void *arg, void *arg2)
{
	t_container *fractol;
	t_thrd *thrd;

	fractol = arg;
	thrd = arg2;
	thrd->cr = (ANGLES == 0) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((long double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->ci = (ANGLES == 1) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((long double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->zr = 0;
	thrd->zi = 0;
	thrd->iter = -1;
	while ((thrd->zr * thrd->zr + thrd->zi * thrd->zi < 4) && (++thrd->iter < ITERMAX))
	{
		thrd->tmp = thrd->zr;
		thrd->zr = thrd->zr * thrd->zr - thrd->zi * thrd->zi + thrd->cr;
		thrd->zi = 2 * thrd->zi * thrd->tmp + thrd->ci;
	}
	if (AV == 1)
	{
		if (thrd->iter != ITERMAX)
			thrd->iter = 0;
	}
	else
		if (thrd->iter == ITERMAX)
			thrd->iter = 0;
	write_data_pixel(fractol, thrd);
}

void	sierpinski(void *arg, void *arg2)
{
	t_container *fractol;
	t_thrd *thrd;

	fractol = arg;
	thrd = arg2;
	thrd->ci = (ANGLES == 0) ? fabsl((long double)thrd->x - CENTRE_W + MODX) : fabsl((long double)thrd->y - CENTRE_H + MODY);
	thrd->cr = (ANGLES == 1) ? fabsl((long double)thrd->x - CENTRE_W + MODX) : fabsl((long double)thrd->y - CENTRE_H + MODY);
	thrd->iter = -1;
	while (((int)thrd->cr % 3 != 1 || ((int)thrd->ci % 3) != 1) && ++thrd->iter < ITERMAX)
	{
		thrd->cr /= 3;
		thrd->ci /= 3;
	}
	if (AV == 1)
	{
		if (thrd->iter == ITERMAX)
			thrd->iter = 1;
	}
	else
		if (thrd->iter != ITERMAX)
			thrd->iter = 1;
	write_data_pixel(fractol, thrd);
}

void	multibrot(void *arg, void *arg2)
{
	t_container *fractol;
	t_thrd *thrd;

	fractol = arg;
	thrd = arg2;
	thrd->cr = (ANGLES == 0) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((long double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->ci = (ANGLES == 1) ? (((long double)thrd->x + XTMP) / ZOOM) - CENTRE_W + MODX : (((long double)thrd->y + YTMP) / ZOOM) - CENTRE_H + MODY;
	thrd->zr = 0;
	thrd->zi = 0;
	thrd->iter = -1;
	while ((thrd->zr * thrd->zr + thrd->zi * thrd->zi < 4) && (++thrd->iter < ITERMAX))
	{
		thrd->tmp = thrd->zr;
		thrd->zr = ((thrd->zr*thrd->zr+thrd->zi*thrd->zi)*((long double)N/2))*(long double)cos((long double)N*(long double)atan2l(thrd->zi,thrd->zr)) + thrd->cr;
		thrd->zi = ((thrd->tmp*thrd->tmp+thrd->zi*thrd->zi)*((long double)N/2))*(long double)sin((long double)N*(long double)atan2l(thrd->zi,thrd->tmp)) + thrd->ci;
	}
	if (AV == 1)
	{
		if (thrd->iter != ITERMAX)
			thrd->iter = 0;
	}
	else
		if (thrd->iter == ITERMAX)
			thrd->iter = 0;
	write_data_pixel(fractol, thrd);
}

/*
mandelbrot z->zˆ3 +c
tmp = zr;
zr = (zr*zr*zr) - 3 * zr * (zi * zi) + cr;
zi = (3 * tmp * 3 * tmp) * zi - (zi*zi*zi) + ci;

mandelbrot z->zˆn + c
tmp = zr;
zr = ((zr*zr+zi*zi)*(N/2))*cos(N*atan2l(zi,zr)) + cr;
zi = ((tmp*tmp+zi*zi)*(N/2))*sin(N*atan2l(zi,tmp)) + ci;
*/

void	*get_fractol(void *arg)
{
	t_container *fractol;
	t_thrd *thrd;
	int x;
	int y;

	thrd = (t_thrd*)arg;
	fractol = thrd->fractol;
	thrd->y = (thrd->i * (HEIGHT / NB_TH)) - 1;
	while (++thrd->y < (HEIGHT / NB_TH) * (thrd->i + 1))
	{
		thrd->x = -1;
		while (++thrd->x < WIDTH)
			fractol->ptrfonct_fractal[FRACTAL](fractol, thrd);
	}
	pthread_exit(0);
}

int	ft_fractol(t_container *fractol)
{
	int i;
	pthread_t thread[NB_TH];
	t_thrd **thrd;

	if (!(thrd = (t_thrd**)malloc(sizeof(t_thrd*) * NB_TH)))
		exit (0);
	i = -1;
	while (++i < NB_TH)
	{
		if (!(thrd[i] = (t_thrd*)malloc(sizeof(t_thrd))))
			exit (0);
		thrd[i]->i = i;
		thrd[i]->fractol = fractol;
		pthread_create(&thread[i], NULL, &get_fractol, thrd[i]);
	}
	i = -1;
	while (++i < NB_TH)
	{
		(void)pthread_join(thread[i], NULL);
		free(thrd[i]);
	}
	free(thrd);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
