/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:51:02 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:39:06 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstiter.c
 * @brief Iterates over a linked list and applies a function to each node.
 *
 * This file implements `ft_lstiter`, which applies a user-defined function
 * to the content of each node in a singly linked list.
 * It does not modify the structure of the list itself.
 * 
 * It is typically used to perform side effects (like printing or logging)
 * on each node’s content.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Iterates over a list and applies a function to each node's content.
 *
 * This function traverses the given linked list and applies the function
 * `f` to the `content` of each node. It does not allocate or free any
 * memory, and it does not modify the list structure.
 *
 * @param lst Pointer to the first node of the list.
 * @param f   Function to apply to the content of each node.
 * 
 * @note The function `f` should not modify the list structure.
 * 
 * @ingroup linked_list
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
