/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:55:15 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/19 00:38:18 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	hash_files(t_parse_ssl *parsing, t_ssl *ssl)
{
	if (!word(parsing) && !OPT(ssl->opt, OPT_DISABLE_READ))
		sum_standard_input(ssl, 0);
	while (word(parsing))
	{
		sum_file(ssl, word(parsing));
		iter(parsing);
	}
}
