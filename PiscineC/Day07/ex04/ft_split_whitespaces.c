/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 23:53:47 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/05 19:35:43 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_word_str(char *str)
{
	int a;
	int nbr_word_str;

	a = 0;
	nbr_word_str = 0;
	while (str[a])
	{
		while ((str[a] == '\n') || (str[a] == '\t') || (str[a] == ' '))
			a++;
		if (str[a] != '\n' && str[a] != '\t' && str[a] != ' ' && str[a] != '\0')
		{
			while (str[a] && (str[a] != '\n' &&
					str[a] != '\t' && str[a] != ' '))
				a++;
			nbr_word_str++;
		}
	}
	return (nbr_word_str);
}

int		cw(int pos_in_str, char *str)
{
	int a;

	a = 0;
	while (str[pos_in_str] && (str[pos_in_str] != '\n') &&
			(str[pos_in_str] != '\t') && (str[pos_in_str] != ' '))
	{
		pos_in_str++;
		a++;
	}
	return (a);
}

int		jump_space(char *str, int b)
{
	while ((str[b] == '\n') || (str[b] == '\t') || (str[b] == ' '))
	{
		b++;
	}
	return (b);
}

char	**cpy_word_str(char **tab, char *str)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	while (str[b])
	{
		c = 0;
		b = jump_space(str, b);
		if (str[b] == '\0')
			return (tab);
		if ((tab[a] = (char*)malloc(sizeof(char) * (cw(b, str) + 1))) == NULL)
			return (NULL);
		while (str[b] && (str[b] != '\n') &&
				(str[b] != '\t') && (str[b] != ' '))
		{
			tab[a][c] = str[b];
			b++;
			c++;
		}
		tab[a][c] = '\0';
		a++;
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	int		nbr_word_str;
	char	**tab;

	nbr_word_str = count_word_str(str);
	if ((tab = (char**)malloc(sizeof(char*) * (nbr_word_str + 1))) == NULL)
		return (NULL);
	tab = cpy_word_str(tab, str);
	tab[nbr_word_str] = NULL;
	return (tab);
}
