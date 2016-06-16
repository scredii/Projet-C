/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:07:12 by ddufour           #+#    #+#             */
/*   Updated: 2016/03/23 11:58:32 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void*, void*))
{
	if (root)
	{
		if (root->left)
			btree_search_item(root->right, data_ref, cmpf);
		if (root->right)
			btree_search_item(root->right, data_ref, cmpf);
		if (cmpf(data_ref, root->item) == 0)
			return (data_ref);
	}
	return (0);
}
