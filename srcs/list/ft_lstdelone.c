/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:50:54 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:57 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdelone.c
 * @brief Deletes a single node of a linked list.
 *
 * This file provides the implementation of `ft_lstdelone`, a function that
 * frees a single list node and its content using a user-provided delete
 * function. This does not affect any other nodes in the list.
 * 
 * It is typically used inside other list-cleaning operations like
 * `ft_lstclear`.
 * 
 * @author nlouis
 * @date 2024/10/19
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Deletes and frees a single list node.
 *
 * Frees the memory of the given list node and its content using the
 * `del` function. The `next` pointer of the node is not accessed or freed.
 *
 * @param lst A pointer to the node to delete.
 * @param del A pointer to the function used to free the content.
 * 
 * @ingroup linked_list
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
