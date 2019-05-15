/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 05:59:10 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/16 05:59:30 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	free_blocks(t_block **block)
{
	if (!*block)
		return ;
	free_blocks(&(*block)->next);
	free((*block)->block);
	(*block)->block = NULL;
	free(*block);
	*block = NULL;
}
