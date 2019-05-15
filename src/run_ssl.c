/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ssl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:22:36 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 02:04:49 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	assign_memory_and_run(unsigned int digest_size
		, unsigned int buffer_size, t_parse_ssl *parsing, t_ssl *ssl)
{
	unsigned char	digest[digest_size];
	char			buffer[buffer_size];

	ssl->digest = digest;
	ssl->buffer = buffer;
	ssl->blocks = NULL;
	parse_options(parsing, ssl);
	hash_files(parsing, ssl);
}

void		run_ssl(int ac, char **av, char **env)
{
	t_ssl		ssl;
	t_parse_ssl	parsing;

	parsing = (t_parse_ssl){ac, av, env};
	ft_bzero(&ssl, sizeof(t_ssl));
	init_hash_infos(&ssl.infos, *av);
	assign_memory_and_run(ssl.infos.digest_size / 8, ssl.infos.block_size / 8
							, &parsing, &ssl);
}
