/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:39:42 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/17 20:24:46 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int a;
	int b;
	int c;
	int d;

	a = 0;
	b = 1;
	c = 0;
	d = 0;
	while (b < length)
	{
		if (f(tab[a++], tab[b++]) <= 0)
			c++;
	}
	a = 0;
	b = 1;
	while (b < length)
	{
		if (f(tab[a++], tab[b++]) >= 0)
			d++;
	}
	if ((c == length - 1) || (d == length - 1) || length == 0)
		return (1);
	else
		return (0);
}
