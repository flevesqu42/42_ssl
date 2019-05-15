/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash_infos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 08:46:41 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/28 01:16:53 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "hash_list.h"

static void	select_hash(t_hash_infos *infos, t_hash_infos *hash_list
							, char *command, int idx)
{
	while (idx--)
		if (!ft_strcmp(hash_list[idx].command, command))
		{
			*infos = hash_list[idx];
			return ;
		}
	error_opt(ERR_OPT_INVALID_COMMAND, command);
}

void		init_hash_infos(t_hash_infos *infos, char *command)
{
	static t_hash_infos	hash_list[] = HASH_LIST;

	select_hash(infos, hash_list, command
					, sizeof(hash_list) / sizeof(t_hash_infos));
}
