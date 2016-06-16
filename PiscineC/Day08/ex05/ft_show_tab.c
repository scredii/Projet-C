/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 02:41:32 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/10 02:44:57 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
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
	ft_putchar('\n');
}

void	ft_print_words_tables(char **tab)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (tab[a])
	{
		while (tab[a][b])
		{
			ft_putchar(tab[a][b]);
			b++;
		}
		ft_putchar('\n');
		a++;
		b = 0;
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int a;

	a = 0;
	while (par[a].str != 0)
	{
		ft_putstr(par[a].str);
		ft_putnbr(par[a].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[a].tab);
		a++;
	}
}
