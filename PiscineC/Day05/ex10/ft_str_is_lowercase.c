/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:17:57 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/02 16:28:30 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] == '\0')
			return (1);
		else if ((str[a] >= 0 && str[a] <= 96)
				|| (str[a] >= 123 && str[a] <= 127))
			return (0);
		a++;
	}
	return (1);
}
