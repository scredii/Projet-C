/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:38:34 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/14 17:21:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_r_power(int nb, int power)
{
	int a;

	if (power >= 1)
	{
		a = nb * (ft_r_power(nb, power - 1));
		return (a);
	}
	else if (power == 1)
		return (nb);
	else if (power == 0)
		return (1);
	return (1);
}

long int	convert_base_ten(char *nbr, char *base_from, int nbr_caract_b_f)
{
	int			a;
	int			b;
	int			nbr_caract_nbr;
	long int	nbr_baseten;

	a = 0;
	while (nbr[a])
		a++;
	nbr_caract_nbr = a - 1;
	nbr_baseten = 0;
	a = -1;
	b = -1;
	while (nbr[++a])
	{
		while (base_from[++b])
			if (nbr[a] == base_from[b])
			{
				nbr_baseten += b * ft_r_power(nbr_caract_b_f, nbr_caract_nbr);
				nbr_caract_nbr--;
			}
		b = -1;
	}
	return (nbr_baseten);
}

int			*convert_base_to(long int baseten, int nbr_caract_b_t)
{
	int			*tab;
	int			nbr_step_div;
	long int	nbr;

	nbr = baseten;
	nbr_step_div = 1;
	while (nbr >= nbr_caract_b_t)
	{
		nbr = nbr / nbr_caract_b_t;
		nbr_step_div++;
	}
	if ((tab = (int*)malloc(sizeof(int) * nbr_step_div + 1)) == NULL)
		return (NULL);
	nbr = baseten;
	tab[0] = nbr_step_div;
	while (nbr_step_div > 0)
	{
		tab[nbr_step_div] = nbr % nbr_caract_b_t;
		nbr = nbr / nbr_caract_b_t;
		nbr_step_div--;
	}
	return (tab);
}

char		*cpy(char *base_to, int e, long int base_ten, int d)
{
	int		a;
	int		c;
	int		g;
	int		*tab;
	char	*nbr_b_t;

	a = 1;
	g = 0;
	while (base_to[g])
		g++;
	tab = convert_base_to(base_ten, g);
	d = d + tab[0];
	if ((nbr_b_t = (char*)malloc(sizeof(char) * (d + 1))) == NULL)
		return (NULL);
	while (a <= tab[0])
	{
		c = tab[a];
		nbr_b_t[e] = base_to[c];
		a++;
		e++;
	}
	nbr_b_t[e] = '\0';
	return (nbr_b_t);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	baseten;
	int			d;
	int			e;
	int			g;
	char		*nbr_b_t;

	g = 0;
	while (base_from[g])
		g++;
	e = 0;
	d = 0;
	if (nbr[0] == '-')
	{
		d = 1;
		e = 1;
		baseten = convert_base_ten(&nbr[1], base_from, g);
	}
	else
		baseten = convert_base_ten(nbr, base_from, g);
	nbr_b_t = cpy(base_to, e, baseten, d);
	if (nbr[0] == '-')
		nbr_b_t[0] = '-';
	return (nbr_b_t);
}
