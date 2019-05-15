/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:47:47 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 02:24:18 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			new_block(t_ssl *ssl, char *message, int len)
{
	t_block	*new;

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		error(ERR_MALLOC_FAILED);
	new->block = (unsigned char*)ft_memalloc((ssl->infos.block_size / 8)
		* sizeof(unsigned char));
	ft_memcpy(new->block, message, len);
	new->next = ssl->blocks;
	ssl->blocks = new;
	ssl->len += len;
}
