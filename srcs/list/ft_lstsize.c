/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:54:38 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:08:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_lstsize()
 * Counts the number of nodes in a linked list.
 *
 * @lst: The head node of the list.
 *
 * Returns: The total number of nodes in the list.
 *
 * Usage:
 * - Use `ft_lstsize()` to get the length of a linked list.
 * - Returns 0 if the list is empty.
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
