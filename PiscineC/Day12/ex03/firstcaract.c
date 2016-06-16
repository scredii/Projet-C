/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstcaract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 18:30:14 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/08 14:38:40 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void	firstcaract(char *str, int c)
{
	char	*caract;
	int		size_str;
	int		a;
	int		b;

	if ((caract = (char*)malloc(sizeof(char) * (c + 1))) == NULL)
		return ;
	size_str = ft_strlen(str);
	a = 0;
	while (a < (c - size_str))
	{
		caract[a] = '0';
		a++;
	}
	b = 0;
	while (a < c)
	{
		caract[a] = str[b];
		a++;
		b++;
	}
	caract[a] = '\0';
	ft_putstr(caract);
}
