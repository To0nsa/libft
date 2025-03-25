/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:35 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:09:06 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstadd_front()
 * Adds a new node at the start of a linked list.
 *
 * @lst: A pointer to the first node of the list.
 * @new: The new node to be added at the front.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Use `ft_lstadd_front()` to prepend a node to an existing linked list.
 * - If the list is empty (`*lst == NULL`), the new node becomes the first node.
 * - Does nothing if `lst` or `new` is NULL.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
