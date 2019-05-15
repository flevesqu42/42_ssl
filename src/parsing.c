/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 07:02:45 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/18 19:55:36 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*word(t_parse_ssl *parsing)
{
	if (!parsing->ac)
		return (NULL);
	return (*parsing->av);
}

char	*iter(t_parse_ssl *parsing)
{
	if (!parsing->ac)
		return (NULL);
	parsing->ac -= 1;
	parsing->av += 1;
	return (word(parsing));
}
