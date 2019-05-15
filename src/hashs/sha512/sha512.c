/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:26:47 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/27 23:42:23 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hashs/sha512.h"

static void	internal_update(t_sha512 *s, uint64_t *w)
{
	int			i;
	uint64_t	temp1;
	uint64_t	temp2;

	i = 0;
	while (i < 80)
	{
		temp1 = s->h + ((rightrotate_64(s->e, 14)) ^ (rightrotate_64(s->e, 18))
			^ (rightrotate_64(s->e, 41))) + ((s->e & s->f) ^ ((~(s->e)) & s->g))
			+ s->k[i] + w[i];
		temp2 = ((rightrotate_64(s->a, 28)) ^ (rightrotate_64(s->a, 34))
			^ (rightrotate_64(s->a, 39))) + ((s->a & s->b) ^ (s->a & s->c)
			^ (s->b & s->c));
		s->h = s->g;
		s->g = s->f;
		s->f = s->e;
		s->e = s->d + temp1;
		s->d = s->c;
		s->c = s->b;
		s->b = s->a;
		s->a = temp1 + temp2;
		++i;
	}
}

static void	init_w(uint64_t *w, t_block *current)
{
	int			i;
	uint64_t	s0;
	uint64_t	s1;

	i = 0;
	while (i < 16)
	{
		w[i] = ft_rev_bytes_64(((uint64_t*)current->block)[i]);
		++i;
	}
	while (i < 80)
	{
		s0 = (rightrotate_64(w[i - 15], 1)) ^ (rightrotate_64(w[i - 15], 8))
			^ (w[i - 15] >> 7);
		s1 = (rightrotate_64(w[i - 2], 19)) ^ (rightrotate_64(w[i - 2], 61))
			^ (w[i - 2] >> 6);
		w[i] = w[i - 16] + s0 + w[i - 7] + s1;
		++i;
	}
}

static void	update(t_block *current, t_sha512 *s)
{
	uint64_t	w[80];

	init_w(w, current);
	s->a = s->h0;
	s->b = s->h1;
	s->c = s->h2;
	s->d = s->h3;
	s->e = s->h4;
	s->f = s->h5;
	s->g = s->h6;
	s->h = s->h7;
	internal_update(s, w);
	s->h0 = s->h0 + s->a;
	s->h1 = s->h1 + s->b;
	s->h2 = s->h2 + s->c;
	s->h3 = s->h3 + s->d;
	s->h4 = s->h4 + s->e;
	s->h5 = s->h5 + s->f;
	s->h6 = s->h6 + s->g;
	s->h7 = s->h7 + s->h;
}

void		sha512(t_ssl *ssl)
{
	t_sha512	s;
	t_block		*current;

	init_sha512(ssl, &s);
	current = ssl->blocks;
	while (current)
	{
		update(current, &s);
		current = current->next;
	}
	((uint64_t*)ssl->digest)[0] = ft_rev_bytes_64(s.h0);
	((uint64_t*)ssl->digest)[1] = ft_rev_bytes_64(s.h1);
	((uint64_t*)ssl->digest)[2] = ft_rev_bytes_64(s.h2);
	((uint64_t*)ssl->digest)[3] = ft_rev_bytes_64(s.h3);
	((uint64_t*)ssl->digest)[4] = ft_rev_bytes_64(s.h4);
	((uint64_t*)ssl->digest)[5] = ft_rev_bytes_64(s.h5);
	((uint64_t*)ssl->digest)[6] = ft_rev_bytes_64(s.h6);
	((uint64_t*)ssl->digest)[7] = ft_rev_bytes_64(s.h7);
}
