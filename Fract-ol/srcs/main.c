/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:48:24 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 16:57:20 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void		get_fractal(t_container *fractol, char *av)
{
	FRACTAL = -1;
	FRACTAL = (ft_strcmp(av, "sierpinski") == 0) ? 2 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "mandelbrot") == 0) ? 0 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "multibrot") == 0) ? 3 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "julia") == 0) ? 1 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "multijulia") == 0) ? 4 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "tricorn") == 0) ? 5 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "mandelperp") == 0) ? 6 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "celticmandel") == 0) ? 7 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "celticperp") == 0) ? 8 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "burningshipperp") == 0) ? 9 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "buffaloperp") == 0) ? 10 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom1") == 0) ? 11 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom2") == 0) ? 12 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom3") == 0) ? 13 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom4") == 0) ? 14 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom5") == 0) ? 15 : FRACTAL;
	FRACTAL = (ft_strcmp(av, "custom6") == 0) ? 16 : FRACTAL;
	if (FRACTAL == -1)
		exit(msg_error(0));
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
	init_ptrfonct(fractol);
	get_fractal(fractol, av);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 800 + (100 * i), 500, WIDTH, HEIGHT, "Fract'ol");
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &BPP, &SIZELINE, &ENDIAN);
	return (fractol);
}

void		print_info(void)
{
	ft_putendl("Move with : [A,W,S,D]");
	ft_putendl("Less or More itterration : [Q,E]");
	ft_putendl("Zoom key : [R,F]");
	ft_putendl("Rotation : [~]");
	ft_putendl("initial position : [TAB]");
	ft_putendl("Change display : [C]");
	ft_putendl("Active variation for julia : [SPACE]");
	ft_putendl("Less or more red color : [T,Y]");
	ft_putendl("Less or more green color : [G,H]");
	ft_putendl("Less or more blue color : [B,N]");
	ft_putendl("Less or more exponent for mullti[brot][julia] : [Z,X]");
	ft_putendl("Zoom in : [LMB or Scroll Up]");
	ft_putendl("Zoom out : [RMB or Scroll Down]");
}

int			main(int ac, char **av)
{
	t_container	*fractol;
	int			i;

	i = 0;
	if (ac < 2)
		return (msg_error(0));
	while (++i < ac)
	{
		if (fork())
		{
			if (!(fractol = creat_struct(av[i], i)))
				exit(msg_error(1));
			if (i == 1)
				print_info();
			mlx_loop_hook(MLX, ft_fractol, fractol);
			mlx_hook(WIN, KeyPress, KeyPressMask, key_fonc, fractol);
			mlx_hook(WIN, MotionNotify, ButtonMotionMask, motion_mouse,
						fractol);
			mlx_hook(WIN, DestroyNotify, Button1MotionMask, exit_prog, fractol);
			mlx_hook(WIN, ButtonPress, ButtonPressMask, button_fonc, fractol);
			mlx_loop(MLX);
		}
	}
	return (0);
}
