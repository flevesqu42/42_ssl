/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:26:46 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 03:59:26 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hashs/md5.h"

static void		update(t_md5 *h, uint32_t *m)
{
	int	i;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			h->f = ((h->b & h->c) | (~(h->b) & h->d))
					+ h->a + h->k[i] + m[i];
		else if (i < 32)
			h->f = ((h->d & h->b) | (~(h->d) & h->c))
					+ h->a + h->k[i] + m[((5 * i) + 1) % 16];
		else if (i < 48)
			h->f = (h->b ^ h->c ^ h->d)
					+ h->a + h->k[i] + m[((3 * i) + 5) % 16];
		else
			h->f = (h->c ^ (h->b | ~(h->d)))
					+ h->a + h->k[i] + m[(7 * i) % 16];
		h->a = h->d;
		h->d = h->c;
		h->c = h->b;
		h->b = h->b + leftrotate_32(h->f, h->s[i]);
		++i;
	}
}

void			md5(t_ssl *ssl)
{
	t_block		*current;
	t_md5		md5;

	init_md5(ssl, &md5);
	current = ssl->blocks;
	while (current)
	{
		md5.a = md5.a0;
		md5.b = md5.b0;
		md5.c = md5.c0;
		md5.d = md5.d0;
		update(&md5, (uint32_t*)current->block);
		md5.a0 += md5.a;
		md5.b0 += md5.b;
		md5.c0 += md5.c;
		md5.d0 += md5.d;
		current = current->next;
	}
	((uint32_t*)ssl->digest)[0] = md5.a0;
	((uint32_t*)ssl->digest)[1] = md5.b0;
	((uint32_t*)ssl->digest)[2] = md5.c0;
	((uint32_t*)ssl->digest)[3] = md5.d0;
}
