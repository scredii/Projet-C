/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 09:57:47 by ddufour           #+#    #+#             */
/*   Updated: 2016/05/24 11:40:51 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_free(char **tab)
{
	int a;

	a = -1;
	while (tab[++a])
		free(tab[a]);
	free(tab);
}

int		ft_strlen(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	a;
	int	nbr;
	int	negative;

	nbr = 0;
	negative = 0;
	a = 0;
	while ((str[a] == '\n') || (str[a] == '\t') || (str[a] == '\v') ||
			(str[a] == ' ') || (str[a] == '\f') || (str[a] == '\r'))
		a++;
	if (str[a] == '-')
		negative = 1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while ((str[a] >= '0') && (str[a] <= '9'))
	{
		nbr *= 10;
		nbr += str[a] - '0';
		a++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
