/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwises.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:59:42 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 04:05:33 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

uint32_t	rightrotate_32(uint32_t x, uint32_t c)
{
	return ((x >> c) | (x << (32 - c)));
}

uint64_t	rightrotate_64(uint64_t x, uint64_t c)
{
	return ((x >> c) | (x << (64 - c)));
}

uint32_t	leftrotate_32(uint32_t x, uint32_t c)
{
	return ((x << c) | (x >> (32 - c)));
}

uint64_t	leftrotate_64(uint64_t x, uint64_t c)
{
	return ((x << c) | (x >> (64 - c)));
}
