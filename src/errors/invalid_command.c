/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:30:27 by flevesqu          #+#    #+#             */
/*   Updated: 2019/05/15 17:18:11 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

static void	standard_commands(void)
{
	ft_putstr_fd("\nStandard commands:\n", 2);
}

static void	message_digest_commands(void)
{
	ft_putstr_fd("\nMessage Digest commands:\n", 2);
	ft_putstr_fd("md5\n", 2);
	ft_putstr_fd("sha256\n", 2);
	ft_putstr_fd("sha512\n", 2);
}

static void	cipher_commands(void)
{
	ft_putstr_fd("\nCipher commands:\n", 2);
}

void		error_invalid_command(const char *command)
{
	ft_putstr_fd("ft_ssl: Error: '", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd("' is an invalid command.\n", 2);
	standard_commands();
	message_digest_commands();
	cipher_commands();
}
