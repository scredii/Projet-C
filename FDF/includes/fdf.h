/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:09:18 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/31 12:23:38 by ddufour          ###   ########.fr       */
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

# define MLX info_map->window->mlx
# define WIN info_map->window->mlx_window
# define IMG info_map->window->image
# define DATA info_map->window->data
# define WIDTH info_map->window->width
# define HEIGHT info_map->window->height
# define ENDIAN info_map->window->endian
# define SIZELINE info_map->window->size_line
# define BPP info_map->window->bpp
# define XMAX info_map->window->x_max
# define YMAX info_map->window->y_max

# define MODW info_map->modif_pos->modif_width
# define MODH info_map->modif_pos->modif_height
# define ZOOM info_map->modif_pos->zoom
# define MODZ info_map->modif_pos->modif_z
# define DEGREE info_map->modif_pos->degree
# define INCLI info_map->modif_pos->inclination

# define X1 info_map->position->x1
# define X2 info_map->position->x2
# define Y1 info_map->position->y1
# define Y2 info_map->position->y2
# define COLORTMP info_map->position->colortmp

# define DX1 info_map->bress->dx1
# define DX2 info_map->bress->dx2
# define DY1 info_map->bress->dy1
# define DY2 info_map->bress->dy2
# define LONGEST info_map->bress->longest
# define SHORTEST info_map->bress->shortest
# define NUMERATOR info_map->bress->numerator

typedef struct		s_lstmap
{
	float			z;
	int				y;
	int				x;
	int				color;
	struct s_lstmap	*next;
}					t_lstmap;

typedef struct		s_bressenham
{
	int				dx1;
	int				dx2;
	int				dy1;
	int				dy2;
	int				longest;
	int				shortest;
	int				numerator;
}					t_bressenham;

typedef struct		s_param_win
{
	void			*mlx;
	void			*mlx_window;
	void			*image;
	char			*data;
	int				endian;
	int				width;
	int				height;
	int				size_line;
	int				bpp;
	int				x_max;
	int				y_max;
}					t_param_win;

typedef struct		s_modif_param
{
	int				modif_width;
	int				modif_height;
	int				zoom;
	float			modif_z;
	float			degree;
	float			inclination;
}					t_modif_param;

typedef struct		s_pos_pixel
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				colortmp;
}					t_pos_pixel;

typedef struct		s_database
{
	t_lstmap		*lst;
	t_param_win		*window;
	t_pos_pixel		*position;
	t_modif_param	*modif_pos;
	t_bressenham	*bress;
}					t_database;

void	get_pos(t_lstmap *cpy1, t_lstmap *cpy2, t_database *info_map);
int		creat_lst(t_database **info_map, char *av);

#endif
