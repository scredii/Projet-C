/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:42:59 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/28 02:47:55 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int a;

	a = 0;
	if ((nb == 1) || (nb == 0))
		return (1);
	else if ((nb > 0) && (nb < 13))
	{
		a = nb * (ft_recursive_factorial(nb - 1));
		return (a);
	}
	else
		return (0);
}
