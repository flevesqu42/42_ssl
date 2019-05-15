/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:11:01 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/16 10:13:38 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	critical(int err)
{
	if (ERR_IS_CRITICAL(err))
		exit(1);
}

void		error(const int err)
{
	static void (*f[])(void) = {
		usage,
		error_read_failed,
		error_malloc_failed,
	};

	f[ERR_IDX(err)]();
	critical(err);
}

void		error_opt(const int err, const char *opt)
{
	static void (*f[])(const char*) = {
		error_invalid_command,
		error_invalid_option,
		error_no_argument_option,
		error_open_file,
	};

	f[ERR_IDX(err)](opt);
	critical(err);
}
