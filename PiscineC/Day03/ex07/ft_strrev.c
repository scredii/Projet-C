/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 02:34:47 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/25 05:46:51 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int			a;
	int			b;
	char		saveb;

	a = 0;
	b = 0;
	while (str[b])
	{
		b++;
	}
	b--;
	while (a < b)
	{
		saveb = str[b];
		str[b] = str[a];
		str[a] = saveb;
		a++;
		b--;
	}
	return (str);
}
