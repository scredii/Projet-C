/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:12:38 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/03 15:16:20 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (src[b])
	{
		if (b < nb)
		{
			dest[a] = src[b];
		}
		else if (b >= nb)
		{
			dest[a] = '\0';
		}
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
