/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:47:20 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/17 17:46:10 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

void	do_op(char *nbr, char *operateur, char *nbr2);
int		ft_atoi(char *str);
void	addition(int a, int b);
void	division(int a, int b);
void	modulo(int a, int b);
void	multiplication(int a, int b);
void	soustraction(int a, int b);
void	ft_putnbr(int nb);

#endif
