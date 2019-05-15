/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 01:51:25 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/28 01:18:47 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** To handle a new hash, check instructions in `hash_list.h`
*/

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "error.h"

# include <unistd.h>
# include <fcntl.h>
# include <math.h>

/*
** Debugging mode, compile with `make DEBUG=true` to activate.
*/

# ifdef DEBUGFLAG
#  define DEBUG(a)	(a)
# else
#  define DEBUG(_)
# endif

/*
** OPTIONS
*/

enum	e_opt
{
	OPT_QUIET = (0x1 << 4),
	OPT_REVERSE = (0x1 << 5),
	OPT_DISABLE_READ = (0x1 << 6),
	OPT_DEBUG = (0x1 << 7),
};

# define OPT(a, b)	(a & b)

/*
** STRUCTURES
*/

struct s_ssl;

/*
** Informations structure, handle hash name, command line, digest size,
** block size and hash function.
**
** They are defined in `hash_list.h`.
*/

typedef struct	s_hash_infos
{
	char			*name;
	char			*command;
	unsigned int	digest_size;
	unsigned int	block_size;
	void			(*function)(struct s_ssl *ssl);
}				t_hash_infos;

/*
** Linked blocks structure.
*/

typedef struct	s_block
{
	unsigned char	*block;
	struct s_block	*next;
}				t_block;

/*
** General structure for checksum usage.
*/

typedef struct	s_ssl
{
	unsigned int	opt;
	char			*buffer;
	unsigned char	*digest;
	t_block			*blocks;
	size_t			len;
	t_hash_infos	infos;
}				t_ssl;

/*
** Command line interface parsing structure.
*/

typedef	struct	s_parse_ssl
{
	int		ac;
	char	**av;
	char	**env;
}				t_parse_ssl;

/*
** PROTOTYPES
*/

/*
** hash list
*/

void			md5(t_ssl *ssl);
void			sha256(t_ssl *ssl);
void			sha512(t_ssl *ssl);

/*
** init
*/

void			init_hash_infos(t_hash_infos *infos, char *command);

/*
** parsing
*/

char			*iter(t_parse_ssl *parsing);
char			*word(t_parse_ssl *parsing);

/*
** ssl
*/

void			run_ssl(int ac, char **av, char **env);

/*
** parse options
*/

void			parse_options(t_parse_ssl *parsing, t_ssl *ssl);

/*
** hash files
*/

void			hash_files(t_parse_ssl *parsing, t_ssl *ssl);

/*
** sum
*/

void			sum_file(t_ssl *ssl, char *file);
void			sum_string(t_ssl *ssl, char *string, int len);
void			sum_standard_input(t_ssl *ssl, int echo);

/*
** blocks
*/

void			get_blocks_from_string(t_ssl *ssl, char *string, int len);
void			get_blocks_from_fd(t_ssl *ssl, int fd);
void			new_block(t_ssl *ssl, char *message, int len);
void			reverse_blocks(t_ssl *ssl);
void			display_blocks(const size_t len, t_block *block);
void			display_memory(int block_size, t_block *block);
void			free_blocks(t_block **block);
void			save_memory_in_blocks(t_ssl *ssl, size_t *l, const size_t s);

/*
** display
*/

void			display_digest(t_ssl *ssl);
void			display_file(t_ssl *ssl, char *file_name);
void			display_string(t_ssl *ssl, char *string);

#endif
