/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:16:44 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/14 15:51:49 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SIZE_BUFF 4096

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

void	ft_errno(char *av)
{
	if (errno == EACCES)
	{
		ft_putstr("cat");
		ft_putstr(": ");
		ft_putstr(av);
		ft_putstr(": Permission Denied\n");
	}
	else if (errno == EISDIR)
	{
		ft_putstr("cat");
		ft_putstr(": ");
		ft_putstr(av);
		ft_putstr(": Is a directory\n");
	}
	else
	{
		ft_putstr("cat");
		ft_putstr(": ");
		ft_putstr(av);
		ft_putstr(": No such file or directory\n");
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	int		a;
	char	buffer[SIZE_BUFF];

	if (ac < 2)
		return (0);
	a = 1;
	while (a < ac)
	{
		fd = open(av[a], O_RDWR);
		if (fd == -1)
			ft_errno(av[a]);
		else
			while ((ret = read(fd, buffer, SIZE_BUFF)) > 0)
				write(1, buffer, ret);
		close(fd);
		a++;
	}
	return (0);
}
