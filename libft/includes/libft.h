/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 19:14:38 by flevesqu          #+#    #+#             */
/*   Updated: 2019/01/25 09:13:52 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "get_next_line.h"
# include "libftprintf.h"
# include "ft_string.h"

# define T_FLAGS				unsigned int

# define _FLAG_NULL				0

# define _CLEAR_FLAG(f, a)		(f) = ((f) & (~0ull ^ (a)))
# define _REPLACE_FLAG(f, a, b)	(f) = (((f) & (~0ull ^ (a))) | (b))
# define _ADD_FLAG(f, a)		(f) |= (a)
# define _FLAG_SET(f, x)		((f) & (x))

# define _MIN(a, b)				((a) < (b) ? (a) : (b))
# define _MAX(a, b)				((a) > (b) ? (a) : (b))

# define _ARRAY_LEN(s)			(sizeof(s) / sizeof(typeof(*s)))

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
}				t_dlist;

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

typedef struct	s_heuristic
{
	int		heuristic;
	void	*data;
}				t_heuristic;

uint32_t		rightrotate_32(uint32_t x, uint32_t c);
uint64_t		rightrotate_64(uint64_t x, uint64_t c);
uint32_t		leftrotate_32(uint32_t x, uint32_t c);
uint64_t		leftrotate_64(uint64_t x, uint64_t c);

uint32_t		ft_rev_bytes_32(uint32_t i);
uint64_t		ft_rev_bytes_64(uint64_t i);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);

size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strstr_nocase(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strcmp_nocase(const char *s1, const char *s2);
int				ft_strncmp_nocase(const char *s1, const char *s2, size_t n);
void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s1);
char			**ft_strsplit(const char *s, char c);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strscat(char *s1, char *s2);
char			*ft_strsubc(char *s1, const char *s2, size_t *n);

size_t			ft_unsignlen(size_t i);
char			*ft_ifstrrchr(char *s, int c);
int				ft_atoi(const char *s1);
int				ft_atoi_base(const char *s1, int base);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_itoa(int n);
char			*ft_utoasub(size_t nb, char *buf);
int				ft_putchar(int c);
void			ft_putstr(const char *s);
void			ft_putendl(const char *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(const char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_dlist			*ft_dlstnew(const void *content, size_t content_size);
void			ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t));
void			ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void			ft_dlstadd(t_dlist **alst, t_dlist *n);
void			ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
t_dlist			*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
void			ft_dlstswap(t_dlist *lst1, t_dlist *lst2);
t_dlist			*ft_dlstlast(t_dlist **lst);
t_dlist			*ft_dlstgetn(t_dlist **lst, size_t n);
void			ft_dlstaddn(t_dlist **lst, size_t n, t_dlist *nw);
int				get_next_line(int fd, char **line);
int				ft_isspace(int c);
char			*ft_getenv(char **env, char *toget);
char			**ft_splitwhitespaces(const char *s);
void			ft_free_2d(char **tab);
t_heuristic		ft_new_heuristic(void *data, int heuristic);

t_list			*ft_lstpushnew(t_list **first, void *data);
t_list			*ft_lstpushbacknew(t_list **first, void *data);
t_list			*ft_lstnew(void *data);
t_list			*ft_lstinsertsorted(t_list **current, t_list *nw
	, int (*sort_condition)(const void*, const void*));

int				ft_clamp(int i, int min, int max);

#endif
