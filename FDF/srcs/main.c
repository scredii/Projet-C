/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:00:25 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/21 16:51:17 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_fonc(int key_code, t_data *info_fdf)
{
	if (key_code == 53)
		exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data *info_fdf;
	int a;
	void *mlx;
	void *mlx_window;
	int width;
	int height;

	width = 1250;
	height = 750;
	a = 0;
	if (!(info_fdf = creat_tab(av[1])))
		return (0);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, width, height, "FDF");
	mlx_key_hook(mlx_window, key_fonc, info_fdf);
	mlx_loop(mlx);
	return (0);
}


/*while (info_fdf->lst)
	{
		if (a < info_fdf->lst->y)
			ft_putchar('\n');
		a = info_fdf->lst->y;
		ft_putnbr(info_fdf->lst->value);
		if (a == info_fdf->lst->y)
			ft_putchar(' ');
		info_fdf->lst = info_fdf->lst->next;
		}*/










