/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:45:28 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 04:41:06 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		display_digest(t_ssl *ssl)
{
	int	i;
	int	len;

	i = 0;
	len = ssl->infos.digest_size / 8;
	while (i < len)
	{
		ft_printf("%.2x", ssl->digest[i]);
		i++;
	}
}

static void	display(t_ssl *ssl, char *string, int is_string)
{
	if (OPT(ssl->opt, OPT_QUIET))
		display_digest(ssl);
	else if (OPT(ssl->opt, OPT_REVERSE))
	{
		display_digest(ssl);
		ft_printf(is_string ? " \"%s\"" : " %s", string);
	}
	else
	{
		ft_printf(is_string ? "%s (\"%s\") = " : "%s (%s) = "
			, ssl->infos.name, string);
		display_digest(ssl);
	}
	ft_printf("\n");
}

void		display_string(t_ssl *ssl, char *string)
{
	display(ssl, string, 1);
}

void		display_file(t_ssl *ssl, char *file_name)
{
	display(ssl, file_name, 0);
}
