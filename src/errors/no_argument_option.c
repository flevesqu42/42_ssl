/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_argument_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:25:34 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/20 05:19:32 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	error_no_argument_option(const char *option)
{
	ft_putstr_fd("ft_ssl: option require an argument -- ", 2);
	ft_putchar_fd(*option, 2);
	ft_putchar_fd('\n', 2);
	usage();
}
