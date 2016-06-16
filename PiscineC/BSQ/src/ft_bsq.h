/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 10:01:32 by ddufour           #+#    #+#             */
/*   Updated: 2016/05/24 14:34:50 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 10000

char	*ft_charjoin(char *s1, char *s2);
int		check_caract(char **map, char obst, char empty, int ligne_size);
char	**valid_map(char *av, int fd, char **map);
char	*create_tmp_map(char *av, int fd);
char	**create_map(char *tmp_map, char **map);
int		check_map(char *tmp_map);
char	**alloc_map(char *tmp_map, int a, int b, char **map);
void	ft_putchar(char c);
void	ft_free(char **tab);
int		ft_strlen(char *s1);
int		ft_atoi(char *str);
void	print_map(char **map);
void	print_square(char **map, int x, int y, int size);
int		search_square(char **map, int x, int y, char empty);
int		map_resolve(char **map, int x, int c, int e);

#endif
