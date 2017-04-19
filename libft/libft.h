/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:46:46 by framel            #+#    #+#             */
/*   Updated: 2016/12/06 14:29:10 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define BUFF_SIZE 4
# define HEXA(x) "0123456789ABCDEF"[x]
# define OVERSIZET(x) "18446744073709551616"[x]

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	size_t			i;
	size_t			j;
	int				ret;
	char			buf[BUFF_SIZE];
}					t_gnl;

size_t				ft_strlen(const char *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char*s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					t_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				t_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_max3(int a, int b, int c);
int					ft_nbrlen(int long nbr);
int					ft_nbrlen_base(int long nbr, int base);
int					ft_putstr_ret(char const *s);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_addchar(char const *s1, char c);
char				*ft_anbcstr(char a, int n, char b, char c);
int					ft_countchar(const char *str, int c);
void				ft_buffalloc(char **s);
void				ft_buffrealloc(char **s);
void				ft_strbuff(const char *s1, char **s2);
void				ft_strbuffend(const char *s1, char **s2);
int					ft_gnl(int const fd, char **line);
void				ft_lstfifo(t_list **lst, const void *data, size_t size);
void				ft_lstlifo(t_list **lst, const void *data, size_t size);
int					ft_strnjoin(char **line, char *buf, size_t st, size_t len);
size_t				**ft_itabuff(size_t **tab, size_t *line, size_t index);
char				**ft_stabuff(char **tab, char *line, size_t index);
int					ft_isstrsizet(char *nb);
int					ft_isintab(size_t *tab, size_t n);
size_t				ft_atosizet(char *str);
int					ft_error(char *tab);

#endif
