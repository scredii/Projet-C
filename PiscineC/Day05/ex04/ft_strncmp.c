/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 21:52:30 by ddufour           #+#    #+#             */
/*   Updated: 2015/11/01 00:45:40 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int a;

	a = 0;
	while (a < n)
		if (s1[a] && s1[a] == s2[a])
			a++;
		else
			return (s1[a] - s2[a]);
	return (0);
}
