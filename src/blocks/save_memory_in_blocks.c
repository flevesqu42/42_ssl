/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_memory_in_blocks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 08:17:13 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 01:25:19 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	save_memory_in_blocks(t_ssl *ssl, size_t *len, const size_t size)
{
	size_t	bsize;

	bsize = ssl->infos.block_size;
	if (*len % bsize + size > bsize || (*len && !(*len % bsize)))
		new_block(ssl, "", 0);
	*len += size;
}
