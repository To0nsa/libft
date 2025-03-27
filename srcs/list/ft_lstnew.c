/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:54:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:39:16 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstnew.c
 * @brief Creates a new list node.
 *
 * This file contains the implementation of `ft_lstnew`, which creates a
 * new node for a singly linked list and assigns the provided content to it.
 * The new node's `next` pointer is initialized to NULL.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Allocates and initializes a new list node.
 *
 * Allocates memory for a new `t_list` node and sets its `content` to the
 * provided pointer. The `next` pointer of the new node is set to NULL.
 *
 * @param content The content to store in the new node.
 * 
 * @return A pointer to the newly created node, or NULL if allocation fails.
 *
 * @note This function does not copy the content; it stores the pointer
 *       as-is. The caller is responsible for managing the memory of the
 *       content if necessary.
 * 
 * @ingroup linked_list
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
