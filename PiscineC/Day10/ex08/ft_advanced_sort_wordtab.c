/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 23:17:15 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/19 20:48:41 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_tab(char **a, char **b)
{
	char *swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int a;

	a = 0;
	while (tab[a + 1])
	{
		if (cmp(tab[a], tab[a + 1]) > 0)
		{
			swap_tab(&tab[a], &tab[a + 1]);
			a = 0;
		}
		else
			a++;
	}
}
