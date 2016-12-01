/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:26:21 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/17 16:36:41 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strtwo(char *str)
{
	int		a;
	char	*tmp;

	a = ft_strlen(str);
	if (a != 2)
	{
		if ((tmp = (char*)malloc(sizeof(char) * 3)) == NULL)
			return (NULL);
		tmp[0] = '0';
		tmp[1] = str[0];
		tmp[2] = '\0';
	}
	else
		tmp = str;
	return (tmp);
}

void	ft_complign(int a, int flag)
{
	while (a != 16)
	{
		if (flag == 8)
			if (a == 8)
				write(1, " ", 1);
		write(1, "   ", 3);
		a++;
	}
}

char	*ft_concat(char *buftmp, char buffer, int b)
{
	char	*ret;
	int		a;

	a = 0;
	if ((ret = (char*)malloc(sizeof(char) * (b + 1))) == NULL)
		return (NULL);
	if (b != 1)
	{
		while (buftmp[a])
		{
			ret[a] = buftmp[a];
			a++;
		}
	}
	ret[a] = buffer;
	ret[a + 1] = '\0';
	return (ret);
}

void	ft_errno(char *av)
{
	if (errno == EACCES)
	{
		ft_puterrno("hexdump");
		ft_puterrno(": ");
		ft_puterrno(av);
		ft_puterrno(": Permission Denied\n");
	}
	else if (errno == EISDIR)
	{
		ft_puterrno("hexdump");
		ft_puterrno(": ");
		ft_puterrno(av);
		ft_puterrno(": Is a directory\n");
	}
	else
	{
		ft_puterrno("hexdump");
		ft_puterrno(": ");
		ft_puterrno(av);
		ft_puterrno(": No such file or directory\n");
	}
}

void	ft_badfile(char *av)
{
	ft_puterrno("hexdump");
	ft_puterrno(": ");
	ft_puterrno(av);
	ft_puterrno(": Bad file descriptor\n");
}
