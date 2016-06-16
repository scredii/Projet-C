/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:26:54 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/19 05:14:01 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree *btree;

	btree = (t_btree*)malloc(sizeof(t_btree));
	if (btree)
	{
		btree->left = 0;
		btree->right = 0;
		btree->item = item;
	}
	return (btree);
}
