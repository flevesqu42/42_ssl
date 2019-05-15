/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 03:48:22 by flevesqu          #+#    #+#             */
/*   Updated: 2017/06/04 02:23:23 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushnew(t_list **first, void *data)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = *first;
	*first = new;
	return (new);
}

t_list	*ft_lstinsertsorted(t_list **current, t_list *new
	, int (*sort_condition)(const void*, const void*))
{
	while (*current)
	{
		if (sort_condition(new->data, (*current)->data) < 0)
			break ;
		current = &(*current)->next;
	}
	new->next = (*current);
	*current = new;
	return (*current);
}

t_list	*ft_lstpushbacknew(t_list **current, void *data)
{
	while (*current)
		current = &(*current)->next;
	*current = ft_lstnew(data);
	return (*current);
}

t_list	*ft_lstnew(void *data)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->data = data;
	new->next = NULL;
	return (new);
}
