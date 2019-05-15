/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_standard_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 03:33:37 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 01:52:27 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sum_standard_input(t_ssl *ssl, int echo)
{
	get_blocks_from_fd(ssl, 0);
	if (echo)
		display_blocks(ssl->infos.block_size / 8, ssl->blocks);
	ssl->infos.function(ssl);
	free_blocks(&ssl->blocks);
	display_digest(ssl);
	ft_printf("\n");
}
