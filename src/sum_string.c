/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:49:34 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 03:59:29 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		sum_string(t_ssl *ssl, char *string, int len)
{
	get_blocks_from_string(ssl, string, len);
	ssl->infos.function(ssl);
	display_string(ssl, string);
	free_blocks(&ssl->blocks);
}
