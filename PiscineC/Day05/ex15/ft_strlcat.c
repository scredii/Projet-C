/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 15:19:13 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/03 16:27:05 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while(src[b])
		b++;
	if (b + size >= b + a)
		return (b + size);
	else
		return (0);
}
