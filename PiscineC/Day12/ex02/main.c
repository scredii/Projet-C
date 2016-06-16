/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:32:58 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/08 15:14:31 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str)
{
	int i;
	int is_neg;
	int number;

	i = 0;
	is_neg = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		is_neg = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	if (is_neg)
		return (-number);
	else
		return (number);
}

void	ft_opt(int ac, char **av, int fd, int a)
{
	int		count;
	int		len_file;
	char	buffer;
	int		size_octet;

	size_octet = ft_atoi(av[2]);
	count = 0;
	len_file = ft_len_file(av[a]);
	if (ac > 4)
		ft_print_name(av[a], a);
	while ((len_file - size_octet) > count)
		count += read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
}

void	ft_opt_plus(int ac, char **av, int fd, int a)
{
	int		count;
	char	buffer;
	int		size_octet;

	size_octet = ft_atoi(av[2]);
	count = 1;
	if (ac > 4)
		ft_print_name(av[a], a);
	while (size_octet > count)
		count += read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
}

void	ft_display(int ac, char **av, int size_octet)
{
	int len_file;
	int fd;
	int a;

	a = 3;
	while (a < ac)
	{
		fd = open(av[a], O_RDWR);
		if (fd == -1)
			ft_error(av[0], av[a], a);
		else if (av[2][0] == '+')
			ft_opt_plus(ac, av, fd, a);
		else
			ft_opt(ac, av, fd, a);
		close(fd);
		a++;
	}
}

int		main(int ac, char **av)
{
	int	size_octet;

	if (ac < 4)
		return (0);
	size_octet = ft_atoi(av[2]);
	ft_display(ac, av, size_octet);
	return (0);
}
