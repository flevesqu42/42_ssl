/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:03:18 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/23 01:52:25 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	sum_file(t_ssl *ssl, char *file)
{
	int	fd;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		error_opt(ERR_OPEN_FILE, file);
		return ;
	}
	get_blocks_from_fd(ssl, fd);
	ssl->infos.function(ssl);
	free_blocks(&ssl->blocks);
	display_file(ssl, file);
}
