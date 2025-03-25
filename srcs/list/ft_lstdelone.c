/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:54 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:09:31 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstdelone()
 * Deletes and frees a single node from a linked list.
 *
 * @lst: The node to delete.
 * @del: A function used to free the node's content.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Use `ft_lstdelone()` to delete one node without affecting the rest.
 * - Applies `del` to free the content, then frees the node itself.
 * - Does nothing if `lst` or `del` is NULL.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
