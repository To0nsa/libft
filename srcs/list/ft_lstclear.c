/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:44 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstclear.c
 * @brief Clears and frees all nodes of a linked list.
 *
 * This file contains the implementation of `ft_lstclear`, a utility that
 * deletes and frees all nodes of a singly linked list, including the content
 * of each node using a user-provided delete function.
 * 
 * After the operation, the list pointer is set to NULL to prevent dangling
 * pointers.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Frees all nodes of a list and sets the list pointer to NULL.
 *
 * This function iterates through each node of a linked list, deletes the
 * content of each node using the provided `del` function, frees the node
 * itself, and finally sets the list pointer to NULL.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param del A pointer to the function used to delete the content of each node.
 * 
 * @see ft_lstdelone
 * @ingroup linked_list
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
