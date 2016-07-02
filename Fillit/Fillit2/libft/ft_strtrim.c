/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:25:21 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/08 18:27:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = (int)ft_strlen(s) - 1;
	if (b != 0)
	{
		while (s[a] == '\t' || s[a] == ' ' || s[a] == '\n')
			a++;
		while (s[b] == '\t' || s[b] == ' ' || s[b] == '\n')
			b--;
		if (s[a] != '\0')
		{
			if ((str = (char*)ft_memalloc(sizeof(char)
				* b - a + 2)) == NULL)
				return (NULL);
			str = ft_memcpy(str, s + a, b - a + 1);
			return (str);
		}
	}
	if ((str = (char*)ft_memalloc(sizeof(char) * 1)) == NULL)
		return (NULL);
	return (str);
}
