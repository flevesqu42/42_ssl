/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocks_from_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:01:20 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 03:58:34 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		get_blocks_from_string(t_ssl *ssl, char *string, int len)
{
	int	size;

	ssl->opt |= OPT_DISABLE_READ;
	size = ssl->infos.block_size / 8;
	ssl->len = 0;
	while (len > 0)
	{
		new_block(ssl, string, len < size ? len : size);
		len -= size;
	}
	if (!ssl->blocks)
		new_block(ssl, ssl->buffer, 0);
	ssl->len *= 8;
}
