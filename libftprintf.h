/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:33:50 by jauplat           #+#    #+#             */
/*   Updated: 2018/04/25 14:41:07 by jauplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <limits.h>
# include <locale.h>
# include <wchar.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

int			ft_printf(char *format, ...);
int			ft_put(int r, char *format, va_list ap);
int			ft_conversion(va_list ap, char **str, char **format);
int			ft_formatchr(va_list ap, char **str, char **format);
int			ft_indic(va_list ap, char **str, char *format, char *tmp);
char		**ft_decimal(va_list ap, char **str, char *tmp, char *format);
char		ft_addop(char *tmp, char *format, int k, char **s);
int			ft_precision(char *tmp, char *str, int k, char *format);
int			ft_takepos(char **str, char *format, int k[2], char *tmp);
char		*ft_less(char *str, char *tmp, char *format);
char		*ft_width(char **str, int k[2], char *format, char *tmp);
int			ft_check(char *tmp, char *format);
char		*ft_len(va_list ap, char *tmp, char *format);
intmax_t	ft_deci(va_list ap, char *tmp, char *format);
uintmax_t	ft_udeci(va_list ap, char *tmp, char *format);
char		*ft_space(char *str, char *tmp);
char		*ft_hex(va_list ap, char *tmp, char *format);
int			ft_lenhexa(uintmax_t nbr, char *tmp);
char		*ft_sharpe(char *str, char *format, char *tmp);
char		*ft_hexneg(unsigned long long nbr, int i);
char		*ft_hexpos(uintmax_t nb, int i, char *tmp);
char		*ft_string(va_list ap, char *format, char *tmp);
int			ft_printchar(char *str, char *format, char *tmp);
char		*ft_char(va_list ap, char *format, char *tmp);
char		*ft_octal(va_list ap, char *tmp, char *format);
int			ft_lenoctal(uintmax_t nbr, char *tmp);
char		*ft_octalpos(uintmax_t nbr, int i, char *tmp);
char		*ft_uitoa(uintmax_t n, char *tmp);
char		*ft_pointer(va_list ap, char *tmp);
char		*ft_hexpoint(uintmax_t nbr, int i);
void		ft_bigc(wchar_t c, char *s, int len);
int			ft_lenbigc(wchar_t c, char **s, int len);
char		*ft_bigs(wchar_t *s2);
int			ft_lenbigs(wchar_t *s2, int len, int *k);
char		*ft_beginbigs(wchar_t *s2, int len, int i);
int			ft_precbigs(char *str, int p);
char		ft_simplechr(int *len, wchar_t c, int i);
int			main();

#endif
