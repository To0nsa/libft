/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:35 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:49 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front.c
 * @brief Adds a new node at the beginning of a linked list.
 *
 * This file contains the implementation of `ft_lstadd_front`, which prepends
 * a new node to the start of a singly linked list. It is part of the custom
 * linked list utilities in libft.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Adds a new node to the beginning of a linked list.
 *
 * If both the list and the new node are valid, the new node is inserted
 * at the front of the list, and becomes the new head.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The new node to add to the beginning of the list.
 * 
 * @ingroup linked_list
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
