/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:00:25 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/05 11:17:54 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a]);
		a++;
	}
}

int		main(int ac, char **av)
{
	int b;

	b = ac - 1;
	while (b > 0)
	{
		ft_putstr(av[b]);
		ft_putchar('\n');
		b--;
	}
	return (0);
}
