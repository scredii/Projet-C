/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:13:14 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/06 12:20:32 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		ft_putchar(str[a++]);
	}
}

int		main(int ac, char **av)
{
	int b;

	(void)ac;
	b = 1;
	while (av[b])
	{
		ft_putstr(av[b]);
		ft_putchar('\n');
		b++;
	}
	return (0);
}
