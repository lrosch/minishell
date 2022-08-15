/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskowron <hskowron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:46:13 by hskowron          #+#    #+#             */
/*   Updated: 2022/03/29 16:58:30 by hskowron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

char	*ft_strtrim(char const *str, char const *set);
void	*ft_memchr(const void *src, int tar, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *dst, int rep, size_t len);
size_t	ft_strlen(const char *src);
void	*ft_bzero(void *dest, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	*ft_strnstr(const char *src, const char *tar, size_t len);
char	*ft_strrchr(const char *src, int tar);
size_t	ft_strlcpy(void *dst, const void *src, size_t len);
int		ft_atoi(const char *str);
void	*ft_memccpy(void *dst, void *src, int tar, size_t len);
void	*memchr(const void *src, int tar, size_t len);
int		ft_memcmp(const void *str1, const void *str2, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strchr(const char *src, int tar);
int		ft_isalpha(int sub);
int		ft_isdigit(int sub);
int		ft_isalnum(int sub);
int		ft_isprint(int sub);
int		ft_isascii(int sub);
int		ft_toupper(int src);
int		ft_tolower(int src);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_strrchr_ez(const char *str, int tar);
int		ft_get_digits(int nmbr);
void	ft_putnbr(long nbr);
void	ft_putnbr_u(unsigned int nbr);
void	ft_putnbr_lhex(unsigned long nbr);
void	ft_putchar(int chr);
void	ft_putnbr_ihex(unsigned int nbr, int lettcase);
void	ft_strrev(char *str);
int		ft_get_dig_hex(unsigned long nbr);
int		ft_get_digits_u(unsigned int nmbr);
size_t	ft_strlen_mnl(const char *src);
int		ft_strrchr_only(const char *str, int tar);
char	*ft_strmirr(char *dst, char *src);
t_list	*ft_lst_bf_last(t_list *lst);
size_t	ft_arrlen(char **src);
long	ft_atol(const char *str);
char	**check_for_empty(const char *str);
int		ft_strncmpenv(const char *s1, const char *s2, size_t len);
int		ft_isdigit_string(char *str);
char	*ft_strjoin_nl(char const *s1, char const *s2);
char	*ft_strdup_nl(const char *src);
char	*ft_strdup_no_eq(const char *src);
char	**ft_split_export(char *str);

#endif