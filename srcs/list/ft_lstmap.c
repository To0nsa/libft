/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:03:36 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:08:56 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstmap()
 * Creates a new list by applying a function to each node’s content of
 * an existing list.
 *
 * @lst: The head node of the original list.
 * @f: A function to apply to the content of each node.
 * @del: A function to delete the content in case of allocation failure.
 *
 * Returns: A new list with each node’s content transformed by `f`,
 *          or NULL if allocation fails at any point.
 *
 * Usage:
 * - Use `ft_lstmap()` to generate a new list with transformed content
 * 	from another list.
 * - Applies `f` to each node’s content to create new content.
 * - Uses `ft_lstnew()` to create new nodes and `ft_lstadd_back()`
 * 	to append them.
 * - If memory allocation fails, uses `del` to free any created content and
 * 	clears the new list.
 * - Does nothing and returns NULL if `lst` or `f` is NULL.
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
