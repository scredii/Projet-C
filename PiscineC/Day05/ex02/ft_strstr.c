/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 03:11:06 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/31 15:09:45 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int a;
	int b;
	int s_s_c;

	a = 0;
	b = 0;
	while (str[a])
	{
		if (str[a] == to_find[b])
		{
			s_s_c = a;
			while (str[a + b] == to_find[b])
			{
				if (to_find[b + 1] == '\0')
				{
					return (str + s_s_c);
				}
				b++;
			}
		}
		b = 0;
		a++;
	}
	return (0);
}
