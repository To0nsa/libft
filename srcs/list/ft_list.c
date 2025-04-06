/**
 * @file ft_list.c
 * @brief Linked list operations for libft.
 *
 * @details
 * This file implements singly linked list operations for the custom
 * libft library. It includes allocation, traversal, insertion,
 * deletion, mapping, and utility functions. The functions operate
 * on the `t_list` struct which stores a `void*` content pointer
 * and a pointer to the next node.
 *
 * These functions provide a flexible way to manipulate generic
 * data structures, suitable for various use cases including stack,
 * queue, and basic graph algorithms.
 *
 * @author nlouis
 * @date 2025/04/05
 * @ingroup linked_list
 */

#include "libft.h"

/**
 * @brief Allocates and initializes a new list node.
 *
 * @details
 * Allocates memory for a new `t_list` node and sets its `content` to the
 * provided pointer. The `next` pointer of the new node is set to NULL.
 *
 * @param content The content to store in the new node.
 * @return A pointer to the newly created node, or NULL if allocation fails.
 *
 * @note This function does not copy the content; it stores the pointer
 * as-is. The caller is responsible for managing the memory of the
 * content if necessary.
 *
 * @ingroup linked_list
 */
t_list* ft_lstnew(void* content)
{
	t_list* new_node;

	new_node = (t_list*) malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next    = NULL;
	return (new_node);
}

/**
 * @brief Adds a new node to the beginning of a linked list.
 *
 * @details
 * If both the list and the new node are valid, the new node is inserted
 * at the front of the list, and becomes the new head.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The new node to add to the beginning of the list.
 *
 * @ingroup linked_list
 */
void ft_lstadd_front(t_list** lst, t_list* new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst      = new;
}

/**
 * @brief Adds a new node to the end of a linked list.
 *
 * @details
 * If the list is empty, the new node becomes the first node.
 * Otherwise, it is appended to the end of the list.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param new The new node to add to the end of the list.
 *
 * @see ft_lstlast
 * @ingroup linked_list
 */
void ft_lstadd_back(t_list** lst, t_list* new)
{
	t_list* last;

	if (!lst || !new)
		return;
	if (!(*lst))
		*lst = new;
	else
	{
		last       = ft_lstlast(*lst);
		last->next = new;
	}
}

/**
 * @brief Frees the memory pointed to by `content`.
 *
 * @details
 * This function is typically used as a helper for linked list functions
 * that require a function pointer to properly deallocate memory associated
 * with a node's content. It performs a simple `free()` operation on the
 * pointer passed.
 *
 * @param content A pointer to the memory to be freed.
 *
 * @ingroup linked_list
 */
void ft_del(void* content)
{
	free(content);
}

/**
 * @brief Deletes and frees a single list node.
 *
 * @details
 * Frees the memory of the given list node and its content using the
 * `del` function. The `next` pointer of the node is not accessed or freed.
 *
 * @param lst A pointer to the node to delete.
 * @param del A pointer to the function used to free the content.
 *
 * @ingroup linked_list
 */
void ft_lstdelone(t_list* lst, void (*del)(void*))
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
}

/**
 * @brief Frees all nodes of a list and sets the list pointer to NULL.
 *
 * @details
 * This function iterates through each node of a linked list, deletes the
 * content of each node using the provided `del` function, frees the node
 * itself, and finally sets the list pointer to NULL.
 *
 * @param lst A pointer to the pointer to the first node of the list.
 * @param del A pointer to the function used to delete the content of each node.
 *
 * @see ft_lstdelone
 * @ingroup linked_list
 */
void ft_lstclear(t_list** lst, void (*del)(void*))
{
	t_list* current;
	t_list* next_node;

	if (!lst || !del)
		return;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		ft_lstdelone(current, del);
		current = next_node;
	}
	*lst = NULL;
}

/**
 * @brief Retrieves the last node of a linked list.
 *
 * @details
 * Traverses the linked list starting from the head until the last node
 * (the node with `next == NULL`) is found.
 *
 * @param lst Pointer to the head of the list.
 *
 * @return A pointer to the last node in the list, or NULL if the list is empty.
 *
 * @ingroup linked_list
 */
t_list* ft_lstlast(t_list* lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/**
 * @brief Iterates over a list and applies a function to each node's content.
 *
 * @details
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
void ft_lstiter(t_list* lst, void (*f)(void*))
{
	if (!lst || !f)
		return;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/**
 * @brief Applies a function to each element of a list and builds a new list.
 *
 * @details
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
t_list* ft_lstmap(t_list* lst, void* (*f)(void*), void (*del)(void*))
{
	t_list* new_list;
	t_list* new_node;
	void*   new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node    = ft_lstnew(new_content);
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

/**
 * @brief Counts the number of nodes in a linked list.
 *
 * @details
 * Iterates through the list, counting each node until the end is reached.
 *
 * @param lst A pointer to the head of the list.
 *
 * @return The total number of nodes in the list. Returns 0 if the list
 *         is empty.
 *
 * @ingroup linked_list
 */
int ft_lstsize(t_list* lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}