/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 23:37:24 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/02 23:37:30 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strdup(char *src)
{
	int		a;
	char	*str;

	a = 0;
	if ((str = (malloc(sizeof(*src) * (ft_strlen(src) + 1)))) == NULL)
		return (NULL);
	while (src[a])
	{
		str[a] = src[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
