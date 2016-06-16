/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 03:52:43 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/28 04:40:05 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if ((index == 1) || (index == 2))
		return (1);
	else if (index == 0)
		return (0);
	else if (index < 0)
		return (-1);
	else
		return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}
