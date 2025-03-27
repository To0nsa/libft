/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:27 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:46 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 * @brief Adds a new node at the end of a linked list.
 *
 * This file contains the implementation of `ft_lstadd_back`, which appends
 * a new node to the end of a singly linked list.
 * It is part of the custom linked list utilities in libft.
 *
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Adds a new node to the end of a linked list.
 *
 * If the list is empty, the new node becomes the first node.
 * Otherwise, it is appended to the end of the list.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The new node to add to the end of the list.
 * 
 * @see ft_lstlast
 * @ingroup linked_list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
