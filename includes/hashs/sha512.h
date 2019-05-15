/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 22:11:31 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/28 00:09:30 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHA512_H
# define SHA512_H

# define K	{KA,KB}

typedef struct	s_sha512
{
	uint64_t	h0;
	uint64_t	h1;
	uint64_t	h2;
	uint64_t	h3;
	uint64_t	h4;
	uint64_t	h5;
	uint64_t	h6;
	uint64_t	h7;
	uint64_t	*k;
	uint64_t	a;
	uint64_t	b;
	uint64_t	c;
	uint64_t	d;
	uint64_t	e;
	uint64_t	f;
	uint64_t	g;
	uint64_t	h;
}				t_sha512;

void			init_sha512(t_ssl *ssl, t_sha512 *sha);

/*
** private defines
*/

# define KA	K01,K02,K03,K04,K05,K06,K07,K08,K09,K10,K11,K12,K13,K14,K15,K16,K17
# define KB K18,K19,K20,K21,K22,K23,K24,K25,K26,K27

# define K01	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f
# define K02	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019
# define K03	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242
# define K04	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2
# define K05	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235
# define K06	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3
# define K07	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275
# define K08	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5
# define K09	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f
# define K10	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725
# define K11	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc
# define K12	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df
# define K13	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6
# define K14	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001
# define K15	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218
# define K16	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8
# define K17	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99
# define K18	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb
# define K19	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc
# define K20	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec
# define K21	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915
# define K22	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207
# define K23	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba
# define K24	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b
# define K25	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc
# define K26	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a
# define K27	0x5fcb6fab3ad6faec, 0x6c44198c4a475817

#endif
