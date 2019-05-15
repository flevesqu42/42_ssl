/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 01:06:45 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/28 01:19:09 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_LIST_H
# define HASH_LIST_H

/*
** Add a new t_hash_infos in HASH_LIST to handle a new one.
*/

# define HASH_LIST	{I_MD5, I_SHA256, I_SHA512}

# define I_MD5		{I_MD5_A, I_MD5_B}
# define I_MD5_A	.name = "MD5", .command = "md5", .function = md5
# define I_MD5_B	.digest_size = 128, .block_size = 512

# define I_SHA256	{I_SHA256_A, I_SHA256_B}
# define I_SHA256_A	.name = "SHA256", .command = "sha256", .function = sha256
# define I_SHA256_B	.digest_size = 256, .block_size = 512

# define I_SHA512	{I_SHA512_A, I_SHA512_B}
# define I_SHA512_A	.name = "SHA512", .command = "sha512", .function = sha512
# define I_SHA512_B	.digest_size = 512, .block_size = 1024

#endif
