/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 02:38:41 by ddufour           #+#    #+#             */
/*   Updated: 2015/12/10 02:41:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char				*ft_strdup(char *src)
{
	int		a;
	char	*str;

	a = 0;
	if ((str = (char*)malloc(sizeof(*src) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	while (src[a])
	{
		str[a] = src[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *param;
	int			a;

	if ((param = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))) == NULL)
		return (NULL);
	a = 0;
	while (a < ac)
	{
		param[a].size_param = ft_strlen(av[a]);
		param[a].str = ft_strdup(av[a]);
		param[a].copy = ft_strdup(av[a]);
		param[a].tab = ft_split_whitespaces(av[a]);
		a++;
	}
	param[a].str = 0;
	return (&param[0]);
}
