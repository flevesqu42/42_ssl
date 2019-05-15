/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 08:53:09 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/16 08:52:35 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_invalid_option(const char *option)
{
	ft_putstr_fd("ft_ssl: illegal option -- ", 2);
	ft_putchar_fd(*option, 2);
	ft_putchar_fd('\n', 2);
	usage();
}
