/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:14:14 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:44 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_del.c
 * @brief Simple delete function for use with linked list utilities.
 *
 * This file contains the implementation of `ft_del`, a helper function
 * designed to be passed as a deletion function to other linked list 
 * functions such as `ft_lstdelone`, `ft_lstclear`, or `ft_lstmap`.
 * It simply frees the memory pointed to by the given pointer.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Frees the memory pointed to by `content`.
 *
 * This function is typically used as a helper for linked list functions
 * that require a function pointer to properly deallocate memory associated
 * with a node's content. It performs a simple `free()` operation on the
 * pointer passed.
 *
 * @param content A pointer to the memory to be freed.
 * 
 * @ingroup linked_list
 */
void	ft_del(void *content)
{
	free(content);
}
