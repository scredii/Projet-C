/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 12:19:43 by ddufour           #+#    #+#             */
/*   Updated: 2016/09/19 18:24:06 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_map(char *av)
{
	int		ret;
	int		fd;
	char	*map;
	char	buff[BUFF + 1];

	if (!(map = (char*)ft_memalloc(sizeof(char) * 1)))
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buff, BUFF)) != 0)
	{
		buff[ret] = '\0';
		if (!(map = ft_strjoin(map, buff)))
			return (NULL);
	}
	close(fd);
	return (map);
}
