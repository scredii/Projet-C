/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:15:12 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/26 11:29:58 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	init_event(void *structure , int key_code)
{
	t_container *fractol;

	fractol = structure;
	ITERMAX = 50;
	MODX = 0;
	MODY= 0;
	ANGLES = 0;
	ZOOM = 100;
	VX = 0;
	N = 2;
	VY = 0;
	AV = 0;
	XTMP = 0;
	YTMP = 0;
	R = 38000;
	G = 35000;
	B = 40000;
}

void	init_ptrfonct(t_container *fractol, int i)
{
	while (++i <= 280)
		fractol->ptrfonct_eventkey[i] = fonctnullkey;
	fractol->ptrfonct_eventkey[53] = &exit_fonct;
	fractol->ptrfonct_eventkey[48] = &init_event;
	fractol->ptrfonct_eventkey[0] = &move_leftright;
	fractol->ptrfonct_eventkey[2] = &move_leftright;
	fractol->ptrfonct_eventkey[13] = &move_updown;
	fractol->ptrfonct_eventkey[1] = &move_updown;
	fractol->ptrfonct_eventkey[14] = &itermax;
	fractol->ptrfonct_eventkey[12] = &itermax;
	fractol->ptrfonct_eventkey[50] = &modif_angles;
	fractol->ptrfonct_eventkey[15] = &zoom_keyboard;
	fractol->ptrfonct_eventkey[3] = &zoom_keyboard;
	fractol->ptrfonct_eventkey[6] = &fonction_n;
	fractol->ptrfonct_eventkey[7] = &fonction_n;
	fractol->ptrfonct_eventkey[18] = &change_fractal;
	fractol->ptrfonct_eventkey[19] = &change_fractal;
	fractol->ptrfonct_eventkey[20] = &change_fractal;
	fractol->ptrfonct_eventkey[21] = &change_fractal;
	fractol->ptrfonct_eventkey[23] = &change_fractal;
	fractol->ptrfonct_eventkey[17] = &change_r;
	fractol->ptrfonct_eventkey[16] = &change_r;
	fractol->ptrfonct_eventkey[5] = &change_g;
	fractol->ptrfonct_eventkey[4] = &change_g;
	fractol->ptrfonct_eventkey[11] = &change_b;
	fractol->ptrfonct_eventkey[45] = &change_b;
	fractol->ptrfonct_eventkey[8] = &active_variation;
	i = -1;
	while (++i <= 10)
		fractol->ptrfonct_eventmouse[i] = fonctnullmouse;
	fractol->ptrfonct_eventmouse[1] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[2] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[4] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[5] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[3] = &active_variation_m;
}
int get_fractal(t_container *fractol, char *av)
{
	fractol->ptrfonct_fractal[2] = &sierpinski;
	fractol->ptrfonct_fractal[0] = &mandelbrot;
	fractol->ptrfonct_fractal[3] = &multibrot;
	fractol->ptrfonct_fractal[1] = &julia;
	fractol->ptrfonct_fractal[4] = &multijulia;


	if (ft_strcmp(av, "sierpinski") == 0 || ft_strcmp(av, "Sierpinski") == 0)
		return (2);
	if (ft_strcmp(av, "mandelbrot") == 0 || ft_strcmp(av, "Mandelbrot") == 0)
		return (0);
	if (ft_strcmp(av, "multibort") == 0 || ft_strcmp(av, "Multibrot") == 0)
		return (3);
	if (ft_strcmp(av, "julia") == 0 || ft_strcmp(av, "Julia") == 0)
		return (1);
	if (ft_strcmp(av, "multijulia") == 0 || ft_strcmp(av, "Multijulia") == 0)
		return (4);
	return (-1);
}

t_container	*creat_struct(char *av, int i)
{
	t_container *fractol;

	if (!(fractol = (t_container*)malloc(sizeof(t_container))))
		return (0);
	if (!(fractol->window = (t_win_param*)malloc(sizeof(t_win_param))))
		return (0);
	if (!(fractol->event = (t_ev_param*)malloc(sizeof(t_ev_param))))
		return (0);
	init_event(fractol, 0);
	init_ptrfonct(fractol, -1);
	if ((FRACTAL = get_fractal(fractol, av)) == -1)
			return (0);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 100 * i, 500, WIDTH, HEIGHT, "Fract'ol");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (fractol);
}

int		main(int ac, char **av)
{
	t_container *fractol;
	int i;
	pid_t father;

	i = 0;
	if (ac >= 2)
	{
		father = fork();
		if (father == 0)
		{
			wait(NULL);
		}
		if (father > 0 )
		{
			while (++i < ac)
			{
				if (fork())
				{
					if (!(fractol = creat_struct(av[i], i)))
						return (0);
					mlx_loop_hook(MLX, ft_fractol, fractol);
					mlx_hook(WIN, KeyPress, KeyPressMask, key_fonc, fractol);
					mlx_hook(WIN, MotionNotify, ButtonMotionMask, motion_mouse, fractol);
					mlx_hook(WIN, DestroyNotify, Button1MotionMask, exit_prog, fractol);
					mlx_hook(WIN, ButtonPress, ButtonPressMask, button_fonc, fractol);
					mlx_loop(MLX);
				}
			}
		}
	}
	return (0);
}
