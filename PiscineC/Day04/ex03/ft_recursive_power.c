/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 01:14:32 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/28 03:46:48 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int a;

	if (power >= 1)
	{
		a = nb * (ft_recursive_power(nb, power - 1));
		return (a);
	}
	else if (power == 1)
		return (nb);
	else if (power == 0)
	{
		return (1);
	}
	else
		return (0);
}
