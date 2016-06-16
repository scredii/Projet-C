/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:25:28 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/04 18:25:37 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
