/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_blocks_from_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 00:04:41 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 03:49:04 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	get_buffer(char *buffer, int size, int fd)
{
	int	last_nl;
	int	ret;

	last_nl = 0;
	while ((ret = read(fd, buffer + last_nl, size - last_nl)) > 0
			&& ret + last_nl < size)
		last_nl = ret + last_nl;
	if (ret < 0)
		error(ERR_READ_FAILED);
	return (ret + last_nl);
}

void		get_blocks_from_fd(t_ssl *ssl, int fd)
{
	int		size;
	int		len;

	ssl->opt |= OPT_DISABLE_READ;
	size = ssl->infos.block_size / 8;
	ssl->len = 0;
	while ((len = get_buffer(ssl->buffer, size, fd)) > 0)
	{
		new_block(ssl, ssl->buffer, len);
		if (len < size)
			break ;
	}
	if (!ssl->blocks)
		new_block(ssl, "", 0);
	ssl->len *= 8;
}
