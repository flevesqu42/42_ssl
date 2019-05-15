/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 21:39:50 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/28 00:09:47 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hashs/sha512.h"

static void	append_meta_datas(t_ssl *ssl)
{
	size_t		size;
	uint64_t	len;

	size = ssl->len;
	len = ft_rev_bytes_64(ssl->len);
	save_memory_in_blocks(ssl, &size, 8);
	ssl->blocks->block[(ssl->len / 8) % (ssl->infos.block_size / 8)] = 1 << 7;
	save_memory_in_blocks(ssl, &size, 128);
	((uint64_t*)ssl->blocks->block)[(ssl->infos.block_size / 64) - 1] = len;
}

static void	init_variables(t_sha512 *sha)
{
	static uint64_t	k[80] = K;

	sha->k = k;
}

void		init_sha512(t_ssl *ssl, t_sha512 *sha)
{
	sha->h0 = 0x6a09e667f3bcc908;
	sha->h1 = 0xbb67ae8584caa73b;
	sha->h2 = 0x3c6ef372fe94f82b;
	sha->h3 = 0xa54ff53a5f1d36f1;
	sha->h4 = 0x510e527fade682d1;
	sha->h5 = 0x9b05688c2b3e6c1f;
	sha->h6 = 0x1f83d9abfb41bd6b;
	sha->h7 = 0x5be0cd19137e2179;
	init_variables(sha);
	append_meta_datas(ssl);
	reverse_blocks(ssl);
	DEBUG(display_memory(ssl->infos.block_size, ssl->blocks));
}
