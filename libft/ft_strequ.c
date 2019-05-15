/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:53:39 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/03 18:11:59 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2 || *s1 != *s2)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1 += 1;
		s2 += 1;
		if (*s1 != *s2)
			return (0);
	}
	return (1);
}