/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 19:19:51 by ddufour           #+#    #+#             */
/*   Updated: 2015/10/31 21:57:06 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int a;

	a = 0;
	while (s1[a] && s1[a] == s2[a])
	{
		a++;
	}
	return (s1[a] - s2[a]);
}
