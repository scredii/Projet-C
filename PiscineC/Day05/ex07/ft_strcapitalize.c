/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 04:07:17 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/02 15:20:47 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] += 32;
		a++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int a;

	ft_strlowcase(str);
	a = -1;
	while (str[++a])
	{
		if ((str[a] >= 'a' && str[a] <= 'z')
			|| (str[a] >= '0' && str[a] <= '9'))
		{
			if (str[a] >= 'a' && str[a] <= 'z')
			{
				str[a] -= 32;
				a++;
			}
			while ((str[a] >= 'a' && str[a] <= 'z') ||
					(str[a] >= '0' && str[a] <= '9'))
				a++;
		}
	}
	return (str);
}
