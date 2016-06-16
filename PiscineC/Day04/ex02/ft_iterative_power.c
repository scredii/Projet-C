/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 22:23:42 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/28 01:05:23 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int c;
	int i;

	c = 1;
	i = 0;
	if (power >= 0)
	{
		while (i < power)
		{
			c = nb * c;
			i++;
		}
		return (c);
	}
	else
		return (0);
}
