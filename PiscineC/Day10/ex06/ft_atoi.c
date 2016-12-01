/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 23:07:09 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/17 16:12:15 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	a;
	int	nbr;
	int	negative;

	nbr = 0;
	negative = 0;
	a = 0;
	while ((str[a] == '\n') || (str[a] == '\t') || (str[a] == '\v') ||
			(str[a] == ' ') || (str[a] == '\f') || (str[a] == '\r'))
		a++;
	if (str[a] == '-')
		negative = 1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while ((str[a] >= '0') && (str[a] <= '9'))
	{
		nbr *= 10;
		nbr += str[a] - '0';
		a++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
