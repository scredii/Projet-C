/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 23:12:30 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/19 01:14:36 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_tab(char **tab, int a, int b)
{
	char *swap;

	swap = tab[a];
	tab[a] = tab[b];
	tab[b] = swap;
}

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] && s1[a] == s2[a])
	{
		a++;
	}
	return (s1[a] - s2[a]);
}

void	ft_sort_wordtab(char **tab)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (tab[a])
	{
		while (tab[b])
		{
			if (ft_strcmp(tab[a], tab[b]) > 0)
			{
				swap_tab(tab, a, b);
				b = a;
			}
			b++;
		}
		a++;
		b = a;
	}
}
