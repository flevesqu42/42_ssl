/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:32:58 by flevesqu          #+#    #+#             */
/*   Updated: 2017/07/12 03:11:29 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	index;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			index = 0;
			while (s1[index] == s2[index])
			{
				index++;
				if (s2[index] == '\0')
					return ((char*)s1);
			}
		}
		s1 += 1;
	}
	return (NULL);
}

char	*ft_strstr_nocase(const char *s1, const char *s2)
{
	size_t	index;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1)
	{
		if (ft_tolower(*s1) == ft_tolower(*s2))
		{
			index = 0;
			while (ft_tolower(s1[index]) == ft_tolower(s2[index]))
			{
				index++;
				if (s2[index] == '\0')
					return ((char*)s1);
			}
		}
		s1 += 1;
	}
	return (NULL);
}
