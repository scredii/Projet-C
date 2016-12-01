/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 23:50:00 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/02 23:51:32 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		strlen_av(int ac, char **av)
{
	int size_av;
	int a;
	int b;

	a = 0;
	b = 1;
	size_av = 0;
	while (b < ac)
	{
		while (av[b][a])
		{
			a++;
		}
		size_av = size_av + a;
		a = 0;
		b++;
	}
	return (size_av);
}

char	*write_str(int ac, char **av, char *str)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 1;
	c = 0;
	while (b < ac)
	{
		while (av[b][a])
		{
			str[c] = av[b][a];
			a++;
			c++;
		}
		str[c] = '\n';
		c++;
		b++;
		a = 0;
	}
	str[c - 1] = '\0';
	return (str);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		size_av;
	char	*str;

	size_av = strlen_av(argc, argv);
	if ((str = (char*)malloc(sizeof(*str) * (size_av + argc - 1))) == NULL)
		return (NULL);
	write_str(argc, argv, str);
	return (str);
}
