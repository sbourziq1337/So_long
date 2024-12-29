/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:58:55 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:58:58 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*ptr;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
			return ;
		}
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}

t_node	*ft_lstadd_front(t_node *lst, t_node *new)
{
	if (lst && new)
	{
		new->next = lst;
		lst = new;
	}
	return (new);
}

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = content;
	node->next = NULL;
	return (node);
}

t_node	*ft_node(int numbr, t_node *result)
{
	t_node	*new_node;

	new_node = ft_lstnew(numbr);
	if (new_node == NULL)
	{
		write(2, "error\n", 6);
		return (0);
	}
	ft_lstadd_back(&result, new_node);
	return (result);
}
