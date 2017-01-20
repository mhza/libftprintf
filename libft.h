/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:06:02 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 19:41:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <locale.h>
# include <wchar.h>

# define U_MAX_BYTES 4
# define LTYPES "sSpdDioOuUxXcC%"
# define ABS(value)  (value > 0 ? value : -value)

# define FFFFFFF "7777777"

# define HH 1
# define H 2
# define L 3
# define LL 4
# define J 5
# define Z 6

# define S_CHAR 1
# define SHORT_I 2
# define LONG_I 3
# define LONG_LONG_I 4
# define INTMAX_T 5
# define SIZE_T 6

# define U_INT 10
# define U_CHAR 11
# define U_SHORT_I 12
# define U_LONG_I 13
# define U_LONG_LONG_I 14
# define U_INTMAX_T 15

# define DOUBLE 20
# define INT 21
# define WINT_T 22
# define CHAR_PTR 23
# define WCHAR_T_PTR 24
# define VOID_PTR 25

typedef struct	s_arg {
	char	*suffix;
	char	*prefix;
	char	*param;
}				t_arg;

typedef struct	s_flags {
	int		hashtag;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	int		percent;
	int		is_invalid;
	int		dot;
	int		ic;
	int		fc;
	char	type;
	int		emptyc;
	char	*flags;
	int		flags_len;
}				t_flags;

int				ft_printf(char *str, ...);
char			*ft_print_params(char *str, t_flags *sflags, va_list ap,
				int *tl);
char			*ft_print_str(char *str, int *tl);
char			*ft_conv_num(char *param, t_flags *sflags);
void			ft_if_pluspace(t_arg *arg, t_flags *f);
void			ft_if_width(t_arg *arg, t_flags *f);
void			ft_if_precision(t_arg *arg, t_flags *f);
void			ft_special_flags(char *str, t_flags *sflags);
int				ft_set_flags(t_flags *sflags, char *flags, int len);
char			*ft_get_flags(char *str);
char			*ft_uitoa_b(unsigned int value, int base);
char			*ft_ulitoa_b(uintmax_t value, int base);
char			*ft_man_width(char *param, t_flags *sflags);
char			*ft_man_precision(char *param, t_flags *sflags);
char			*ft_man_minus(char *param);
char			*ft_cast_arg(t_flags *flags, va_list ap, int *tl);
char			*ft_ctoa(int c);
wchar_t			*ft_wctoa(wchar_t c);
char			*ft_conv_alpha(char *param, t_flags *sflags);
wchar_t			*ft_conv_walpha(wchar_t *param, t_flags *sflags);
char			*ft_cast_type2(t_flags *f, va_list ap, int *tl);
char			*ft_cast_type(t_flags *f, va_list ap, int base, int *tl);

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, int n);
void			*ft_memcpy (void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little,
	size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
char			*ft_toupperstr(char *str);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(long long int n);
void			ft_putchar(char c);
size_t			ft_putstr(char const *s);
void			ft_putstrl(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbrl(int n);
void			ft_putints(int *tab, int size);
void			ft_puttab_int(int **tab, int size, int size2);
void			ft_puttab_str(char **tab);
size_t			ft_intlen_base(long long n, int base);
size_t			ft_uintlen_base(unsigned long n, int base);
void			ft_putnbr_base(int nb, int base);
int				ft_atoi_base(const char *str, int str_base);
char			*ft_itoa_base(long value, int base);
size_t			ft_wstrlen(const wchar_t *ws);
size_t			ft_wbyteslen(const wchar_t *ws);
size_t			ft_wputstr(const wchar_t *s);
int				ft_wputchar(wchar_t c);
wchar_t			*ft_wstrncpy(wchar_t *dest, const wchar_t *src, size_t n);
char			*ft_wgetchar(wchar_t c);
wchar_t			*ft_wstrncpyp(wchar_t *dest, const wchar_t *src, size_t n);
int				ft_get_nb_wchar(wchar_t *src, int n);
int				ft_get_nb_bytes(wchar_t *src, int n);

#endif
