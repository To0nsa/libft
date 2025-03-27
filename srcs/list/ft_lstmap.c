/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:03:36 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:39:13 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap.c
 * @brief Creates a new list by applying a function to each element of a list.
 *
 * This file contains the implementation of `ft_lstmap`, which constructs a
 * new list by applying a transformation function to each element's content
 * of an existing list. Memory is properly managed and cleanup is performed
 * if any allocation fails during the process.
 * 
 * @author nlouis
 * @date 2024/10/20
 * @ingroup linked_list
 */
#include "libft.h"

/**
 * @brief Applies a function to each element of a list and builds a new list.
 *
 * Iterates through the input list `lst`, applies the function `f` to the
 * content of each node, and creates a new list with the results. If any
 * allocation fails, the entire new list is cleared using the `del` function.
 *
 * @param lst Pointer to the head of the original list.
 * @param f Function to apply to the content of each node.
 * @param del Function used to delete the content of a node if needed.
 * 
 * @return A new list with the transformed content, or NULL if allocation fails.
 *
 * @note This function allocates new memory and performs deep copies of the
 *       transformed content. You must free the returned list when done.
 *
 * @see ft_lstnew
 * @see ft_lstadd_back
 * @see ft_lstclear
 * @ingroup linked_list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (del)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
