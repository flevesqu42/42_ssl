/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 03:28:06 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 03:55:38 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include <errno.h>

# define ERR_CRIT           0x80
# define ERR_IS_CRITICAL(e) (e & ERR_CRIT)
# define ERR_IDX(e)         (e & ~(ERR_CRIT))

/*
** ERRORS WITHOUT ARGUMENTS
*/

enum	e_error
{
	ERR_USAGE = 0x0 | ERR_CRIT,
	ERR_READ_FAILED = 0x1 | ERR_CRIT,
	ERR_MALLOC_FAILED = 0x2 | ERR_CRIT,
};

/*
** ERRORS WITH ONE ARGUMENT
*/

enum	e_error_opt
{
	ERR_OPT_INVALID_COMMAND = 0x0 | ERR_CRIT,
	ERR_OPT_INVALID_OPTION = 0x1 | ERR_CRIT,
	ERR_OPT_NO_ARGUMENT_OPTION = 0x2 | ERR_CRIT,
	ERR_OPEN_FILE = 0x3,
};

/*
** PROTOTYPES
*/

void	error(const int err);
void	error_opt(const int err, const char *opt);

void	usage(void);
void	error_read_failed(void);
void	error_malloc_failed(void);

void	error_invalid_command(const char *command);
void	error_invalid_option(const char *command);
void	error_no_argument_option(const char *option);
void	error_open_file(const char *file);

#endif
