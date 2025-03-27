/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:52:56 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:39:09 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstlast.c
 * @brief Returns the last node of a linked list.
 *
 * This file provides the implementation of `ft_lstlast`, a utility
 * function to retrieve the last element from a singly linked list.
 * 
 * This is useful when appending elements or traversing to the end
 * of a list without modifying it.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Retrieves the last node of a linked list.
 *
 * Traverses the linked list starting from the head until the last node
 * (i.e., the node with `next == NULL`) is found.
 *
 * @param lst Pointer to the head of the list.
 * 
 * @return A pointer to the last node in the list, or NULL if the list is empty.
 * 
 * @ingroup linked_list
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
