/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:06:17 by flevesqu          #+#    #+#             */
/*   Updated: 2017/05/25 23:51:44 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp_nocase(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (n - 1 && ft_tolower(*s1) == ft_tolower(*s2)
				&& ft_tolower(*s1))
		{
			s1 += 1;
			s2 += 1;
			n--;
		}
		return ((unsigned char)ft_tolower(*s1)
			- (unsigned char)ft_tolower(*s2));
	}
	else
		return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n)
	{
		while (n - 1 && *(unsigned char*)s1 == *(unsigned char*)s2
				&& *(unsigned char*)s1)
		{
			s1 += 1;
			s2 += 1;
			n--;
		}
		return (*(unsigned char*)s1 - *(unsigned char*)s2);
	}
	else
		return (0);
}
