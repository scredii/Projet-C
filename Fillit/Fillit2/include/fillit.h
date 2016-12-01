/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 11:32:22 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/14 11:44:21 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAP fillit->map
# define SIZE fillit->size_map_min
# define BUF_SIZE 1000

typedef	struct	s_fillit
{
	char	**tetris;
	char	**map;
	int		tetris_nbr;
	int		size_map_min;
}				t_fillit;

int				map_check(char *av, t_fillit *fillit);
int				nb_tetris(char *map);
int				ft_sqrt(int nb);
void			ft_free(char **map);
char			*ft_push_left(char *tetris);
char			*ft_push_top(char *tetris, char letter, int i, int y);
char			**ft_creat_map(t_fillit *fillit);
char			*ft_reduce_tetris(char *str, int i, int j, int sharp);
void			ft_resolve(t_fillit *fillit);
int				check_same_carac(t_fillit *fllit, char *tetris, int x, int y);
char			*map_recup(char *av);

#endif
