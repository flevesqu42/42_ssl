/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_blocks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 05:58:10 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 01:31:22 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	display_blocks(const size_t len, t_block *block)
{
	if (!block)
		return ;
	display_blocks(len, block->next);
	write(1, block->block, len);
}

void	display_memory(int block_size, t_block *current)
{
	int	i;

	block_size /= 8;
	while (current)
	{
		i = 0;
		while (i < block_size)
		{
			ft_printf("%.3o: %.2x%.2x%.2x%.2x%.2x%.2x%.2x%.2x = %b\n", i
				, current->block[i + 0], current->block[i + 1]
				, current->block[i + 2], current->block[i + 3]
				, current->block[i + 4], current->block[i + 5]
				, current->block[i + 6], current->block[i + 7]
				, *((uint64_t*)&current->block[i]) ? 1 : 0);
			i += 8;
		}
		ft_printf("\n");
		current = current->next;
	}
}
