/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 05:59:58 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/16 06:00:56 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_block	*recursion(t_block *block)
{
	t_block	*last;

	if (!block->next)
		return (block);
	last = recursion(block->next);
	block->next->next = block;
	return (last);
}

void			reverse_blocks(t_ssl *ssl)
{
	t_block	*first;

	first = ssl->blocks;
	ssl->blocks = recursion(ssl->blocks);
	first->next = NULL;
}
