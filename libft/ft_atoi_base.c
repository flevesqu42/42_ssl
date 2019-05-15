/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:06:20 by flevesqu          #+#    #+#             */
/*   Updated: 2017/01/16 21:02:48 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	int		result;
	char	sign;

	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		str += 1;
	sign = *str == '-' ? -1 : +1;
	if (*str == '-' || *str == '+')
		str += 1;
	while ((*str >= '0' && *str <= '0' + base - 1) || (base > 10
			&& ((*str >= 'a' && *str <= 'a' + base - 1)
			|| (*str >= 'A' && *str <= 'A' + base - 1))))
	{
		if (base > 10 && *str >= 'A' && *str <= 'Z')
			result = result * base + *str - 'A' + 10;
		else if (base > 10 && *str >= 'a' && *str <= 'z')
			result = result * base + *str - 'a' + 10;
		else
			result = result * base + *str - '0';
		str += 1;
	}
	return (result * sign);
}
