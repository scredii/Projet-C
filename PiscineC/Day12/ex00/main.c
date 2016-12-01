/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 17:20:28 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/08 15:20:24 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE_BUFF 4096

int		main(int ac, char **av)
{
	int		fd;
	char	buffer[SIZE_BUFF];
	int		ret;

	if (ac != 2)
	{
		if (ac < 2)
			write(1, "File name missing.\n", 19);
		else if (ac > 2)
			write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	while ((ret = read(fd, buffer, SIZE_BUFF)) > 0)
		write(1, buffer, ret);
	close(fd);
}
