/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:09:18 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/26 19:43:54 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include <math.h>
# include <OpenCL/opencl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define HEXA "0123456789ABCDEF"
# define DECI "0123456789"

typedef struct s_lstmap
{
	int z;
	int y;
	int x;
	int color;
	struct s_lstmap *next;
}				t_lstmap;

typedef struct	s_data
{
	t_lstmap	*lst;
	char		*data;
	void		*mlx;
	void		*mlx_window;
	void		*image;
	int			x_max;
	int			y_max;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			colortmp;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	int			modif_width;
	int			modif_height;
	int			zoom;
	float		modif_z;
	float		degree;
	float		inclination;
}				t_data;

t_data		*creat_tab(char *av);

#endif















