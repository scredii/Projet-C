/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 03:36:11 by ddufour           #+#    #+#             */
/*   Updated: 2016/01/27 18:33:33 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef	struct				s_list
{
	void					*data;
	struct s_list			*next;
}							t_list;

t_list						*ft_create_elem(void *data);

#endif
