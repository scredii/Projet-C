/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 12:22:15 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/06 10:41:31 by ddufour          ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] && (s1[a] == s2[a]))
	{
		a++;
	}
	return (s1[a] - s2[a]);
}

void	ft_swap(char **d, char **e)
{
	char *f;

	f = *d;
	*d = *e;
	*e = f;
}

void	specialnorm(char **av)
{
	int b;

	b = 0;
	while (av[b])
	{
		ft_putstr(av[b]);
		ft_putchar('\n');
		b++;
	}
}

int		main(int ac, char **av)
{
	int b;
	int g;

	(void)ac;
	b = 0;
	g = 1;
	if (ac > 1)
	{
		while (g == 1)
		{
			g = 0;
			while (av[++b + 1])
			{
				if (ft_strcmp(av[b], av[b + 1]) > 0)
				{
					ft_swap(&av[b], &av[b + 1]);
					g = 1;
				}
			}
			b = 0;
		}
		specialnorm(&av[b]);
	}
	else
		return (0);
}
