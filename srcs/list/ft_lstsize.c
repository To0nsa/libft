/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:54:38 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:39:19 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize.c
 * @brief Counts the number of elements in a linked list.
 *
 * This file provides the implementation of `ft_lstsize`, a utility function
 * that calculates the number of nodes in a singly linked list by iterating
 * through it from head to tail.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * Iterates through the list, counting each node until the end is reached.
 *
 * @param lst A pointer to the head of the list.
 * 
 * @return The total number of nodes in the list. Returns 0 if the list
 *         is empty.
 * 
 * @ingroup linked_list
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
