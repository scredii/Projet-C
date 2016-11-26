/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:37:22 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/24 17:32:20 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"


void	exit_fonct(void *structure, int key_code)
{
	exit (0);
}

void	fonctnullkey(void *structure, int key_code)
{}

void	fonctnullmouse(void *structure, int button, int x, int y)
{}

void	move_leftright(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	if (FRACTAL == 2)
		MODX += (key_code == 2) ? 5 : -5;
	else
		MODX += (key_code == 2) ? -10 / ZOOM : 10 / ZOOM;
}

void	move_updown(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	if (FRACTAL == 2)
		MODY += (key_code == 1) ? 5 : -5;
	else
		MODY += (key_code == 1) ? -10 / ZOOM : 10 / ZOOM;
}

void	itermax(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ITERMAX += (key_code == 12) && (ITERMAX > 20) ? -10 : 10;
}

void	modif_angles(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ANGLES = (ANGLES == 1) ? 0 : 1;
}

void	zoom_keyboard(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ZOOM /= (key_code == 3 && ZOOM > 10) ? 1.1 : 1;
	ZOOM *= (key_code == 15) ? 1.1 : 1;

}

void	fonction_n(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	N += (key_code == 6 ) ? -1 : 1;
}

void	zoom_in_out(void *structure, int button, int x, int y)
{
	t_container *fractol;

	fractol = structure;
	ZOOM /= ((button == 2 || button == 5) && ZOOM > 10) ? 1.1 : 1;
	ZOOM *= (button == 1 || button == 4) ? 1.1 : 1;
	XTMP = (button == 2 || button == 5) ? (XTMP - (x / 11)) / 1.1 : (XTMP + (x / 11)) * 1.1;
	YTMP = (button == 2 || button == 5) ? (YTMP - (y / 11)) / 1.1 : (YTMP + (y / 11)) * 1.1;
}

int motion_mouse(int x, int y, t_container *fractol)
{
	if (AV == 1)
	{
		VX = (((long double)x - WIDTH / 2) / 150);
		VY = (((long double)y - HEIGHT / 2) / 150);
	}
	return (0);
}

int	key_fonc(int key_code, t_container *fractol)
{

	fractol->ptrfonct_eventkey[key_code](fractol, key_code);
	return (0);
}

int	button_fonc(int button, int x, int y, t_container *fractol)
{
	fractol->ptrfonct_eventmouse[button](fractol, button, x , y);
	return (0);
}

void change_fractal(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ft_putnbrendl(key_code);
	if (key_code == 18)
		FRACTAL = 0;
	if (key_code == 19)
		FRACTAL = 1;
	if (key_code == 20)
		FRACTAL = 2;
	if (key_code == 21)
		FRACTAL = 3;
	if (key_code == 23)
		FRACTAL = 4;
}

void	change_r(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	R += (key_code == 17) ? -100 : 100;
	ft_putstr("R : ");
	ft_putnbrendl(R);
}

void	change_g(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	G += (key_code == 5) ? -100 : 100;
	ft_putstr("G : ");
	ft_putnbrendl(G);
}

void	change_b(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	B += (key_code == 11) ? -100 : 100;
	ft_putstr("B : ");
	ft_putnbrendl(B);
}

void	active_variation(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	AV = AV == 0 ? 1 : 0;
	ft_putstr("AV key : ");
	ft_putnbrendl(AV);

}

void	active_variation_m(void *structure, int button, int x, int y)
{
	t_container *fractol;

	fractol = structure;
	AV = AV == 0 ? 1 : 0;
	ft_putstr("AV mouse : ");
	ft_putnbrendl(AV);
}

int exit_prog(t_container *fractol)
{
	exit (0);
	return (0);
}
