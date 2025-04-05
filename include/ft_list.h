/**
 * @file ft_list.h
 * @author nlouis
 * @date 2025/04/05
 * @brief Linked list for libft.
 *
 * @details
 * This header defines the singly-linked list type `t_list`
 * and the utility functions used to manipulate linked lists.
 *
 * Features include:
 * - Creation of new nodes
 * - Front/back insertion
 * - Deletion and clearing
 * - Mapping and iteration
 *
 * @note
 * - The list is singly linked, meaning each node points only to the next node.
 * - The `content` pointer in each node can point to any type of data.
 * - All functions are `NULL`-safe and follow defensive programming principles.
 * 
 * @ingroup linked_list
 */

 #ifndef FT_LIST_H
 # define FT_LIST_H
 
 /**
  * @defgroup linked_list Linked List Utilities
  * @brief Singly linked list manipulation functions.
  *
  * @details
  * This group contains all the functions related to the manipulation
  * of singly linked lists, including creation, insertion, deletion,
  * traversal, and transformation.
  * 
  * This group includes:
  * - @ref ft_lstnew
  * - @ref ft_lstadd_front
  * - @ref ft_lstsize
  * - @ref ft_lstlast
  * - @ref ft_lstadd_back
  * - @ref ft_lstdelone
  * - @ref ft_lstclear
  * - @ref ft_lstiter
  * - @ref ft_lstmap
  * - @ref ft_del
  *
  * These utilities operate on a `t_list` structure.
  * @{
  */
 
 /**
  * @typedef t_list
  * @brief Node structure for singly linked list.
  *
  * @details
  * Each node contains a generic `void*` content pointer and
  * a pointer to the next node. 
  */
 typedef struct s_list
 {
	 void			*content; ///< Pointer to the node's content.
	 struct s_list	*next;    ///< Pointer to the next node.
 }	t_list;
 
 /**
  * @brief Creates a new list node.
  *
  * @param content The content to store in the node.
  * @return A pointer to the newly created node, or NULL on failure.
  */
 t_list	*ft_lstnew(void *content);
 
 /**
  * @brief Adds a node to the front of a list.
  *
  * @param lst The address of the pointer to the first node.
  * @param new The new node to add.
  */
 void	ft_lstadd_front(t_list **lst, t_list *new);
 
 /**
  * @brief Counts the number of nodes in a list.
  *
  * @param lst The beginning of the list.
  * @return The number of elements in the list.
  */
 int		ft_lstsize(t_list *lst);
 
 /**
  * @brief Returns the last node of the list.
  *
  * @param lst The beginning of the list.
  * @return The last node, or NULL if the list is empty.
  */
 t_list	*ft_lstlast(t_list *lst);
 
 /**
  * @brief Adds a node to the end of a list.
  *
  * @param lst The address of the pointer to the first node.
  * @param new The node to add to the end.
  */
 void	ft_lstadd_back(t_list **lst, t_list *new);
 
 /**
  * @brief Deletes a single node using a deletion function.
  *
  * @param lst The node to delete.
  * @param del The function to delete the content.
  */
 void	ft_lstdelone(t_list *lst, void (*del)(void*));
 
 /**
  * @brief Clears an entire list, deleting all its nodes.
  *
  * @param lst The address of the pointer to the list.
  * @param del The function to delete each node's content.
  */
 void	ft_lstclear(t_list **lst, void (*del)(void*));
 
 /**
  * @brief Applies a function to each element of the list.
  *
  * @param lst The beginning of the list.
  * @param f The function to apply to each node's content.
  */
 void	ft_lstiter(t_list *lst, void (*f)(void *));
 
 /**
  * @brief Creates a new list by applying a function to each node.
  *
  * @param lst The original list.
  * @param f The transformation function.
  * @param del The function to delete content on failure.
  * @return A new list resulting from the transformation, or NULL on error.
  */
 t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
 
 /**
  * @brief Deletes content pointer in a list node (utility function).
  *
  * @param content The content pointer to free.
  */
 void	ft_del(void *content);
 
 /** @} */ // end of linked_list group
 
 #endif /* FT_LIST_H */
 