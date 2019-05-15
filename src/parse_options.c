/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 04:56:46 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/24 21:33:47 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	length_word(char *begin, t_parse_ssl *parsing)
{
	if (!(parsing->ac - 1))
		return (*parsing->env - begin - 2);
	return ((*(parsing->av + 1)) - begin - 2);
}

static void	parse_string_option(char *option, t_parse_ssl *parsing, t_ssl *ssl)
{
	if (*option)
	{
		sum_string(ssl, option, length_word(option - 1, parsing));
		return ;
	}
	if (!iter(parsing))
		error_opt(ERR_OPT_NO_ARGUMENT_OPTION, "s");
	sum_string(ssl, word(parsing), length_word(option, parsing));
}

static void	parse_option(char *option, t_parse_ssl *parsing, t_ssl *ssl)
{
	while (*++option)
		if (*option == 'q')
			ssl->opt |= OPT_QUIET;
		else if (*option == 'r')
			ssl->opt |= OPT_REVERSE;
		else if (*option == 'p')
			sum_standard_input(ssl, 1);
		else if (*option == 's')
		{
			parse_string_option(&option[1], parsing, ssl);
			break ;
		}
		else
			error_opt(ERR_OPT_INVALID_OPTION, option);
}

void		parse_options(t_parse_ssl *parsing, t_ssl *ssl)
{
	while (iter(parsing) && *word(parsing) == '-')
		if (!ft_strcmp(word(parsing), "--"))
			break ;
		else
			parse_option(word(parsing), parsing, ssl);
}
