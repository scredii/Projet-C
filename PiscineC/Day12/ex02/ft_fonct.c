/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 00:28:38 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/08 15:01:08 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		write(1, &str[a], 1);
		a++;
	}
}

void	ft_print_name(char *av, int a)
{
	int b;

	b = 0;
	if (a == 3)
	{
		write(1, "==> ", 4);
		while (av[b])
		{
			write(1, &av[b], 1);
			b++;
		}
		write(1, " <==\n", 5);
	}
	else
	{
		write(1, "\n==> ", 5);
		while (av[b])
		{
			write(1, &av[b], 1);
			b++;
		}
		write(1, " <==\n", 5);
	}
}

void	ft_error(char *name_prog, char *av, int a)
{
	if (errno == EACCES)
	{
		ft_putstr(name_prog);
		ft_putstr(": ");
		ft_putstr(av);
		ft_putstr(": Permission Denied\n");
	}
	else if (errno == EISDIR)
	{
		ft_print_name(av, a);
	}
	else
	{
		ft_putstr(name_prog);
		ft_putstr(": ");
		ft_putstr(av);
		ft_putstr(": No such file or directory\n");
	}
}

int		ft_len_file(char *av)
{
	char	buffer;
	int		count;
	int		fd;

	count = 0;
	fd = open(av, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
		count++;
	close(fd);
	return (count);
}
