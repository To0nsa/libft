/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:51:02 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:09:00 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstiter()
 * Iterates over a linked list and applies a function to each node’s content.
 *
 * @lst: The head node of the list to be traversed.
 * @f: A function pointer that is applied to each node's content.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Use `ft_lstiter()` to apply a function to every node's content in a list.
 * - The function `f` receives each node's content as an argument.
 * - Does nothing if `lst` or `f` is NULL.
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
