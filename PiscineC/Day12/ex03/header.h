/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:09:04 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/17 16:34:58 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define HEXA "0123456789abcdef"
# define DECI "0123456789"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa(int nbr);
void	ft_putstr(char *str);
void	firstcaract(char *str, int c);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
void	ft_hexnoflag(int fd, int b, int ac, int flag);
void	ft_hexflag(int fd, int b, int ac, int flag);
void	ft_one(int count, int flag);
void	ft_two(char buffer, int flag, int a);
char	*ft_strtwo(char *str);
void	ft_complign(int a, int flag);
void	ft_print_third(char *buftmp);
char	*ft_concat(char *buftmp, char buffer, int b);
void	ft_errno(char *av);
void	ft_puterrno(char *str);
void	ft_badfile(char *av);

#endif
