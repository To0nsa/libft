/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:44 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:09:04 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstclear()
 * Deletes and frees the entire list.
 *
 * @lst: A pointer to the first node of the list.
 * @del: A function used to free the content of each node.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Use `ft_lstclear()` to remove and free every node in a linked list.
 * - Applies `del` to the content of each node, then frees the node itself.
 * - Finally sets `*lst` to NULL, indicating an empty list.
 * - Does nothing if `lst` or `del` is NULL.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}
