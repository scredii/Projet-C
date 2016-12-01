/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 21:47:51 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/28 03:00:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int a;

	a = nb;
	if ((nb > 1) && (nb < 13))
	{
		while (nb > 1)
		{
			a = a * (nb - 1);
			nb--;
		}
		return (a);
	}
	else if ((nb == 0) || (nb == 1))
		return (1);
	else
		return (0);
}
