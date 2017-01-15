/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 09:48:57 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/14 19:00:17 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cast_type(t_flags *flags, va_list ap, int base, int *tl)
{
	if (ft_strchr("di", flags->type))
		return (ft_conv_num(ft_itoa(va_arg(ap, int)), flags));
	else if (ft_strchr("uoxX", flags->type))
		return (ft_conv_num(ft_uitoa_b(va_arg(ap, wint_t), base), flags));
	else if (ft_strchr("fFeEgGaA", flags->type))
		return (ft_conv_num(va_arg(ap, char*), flags));
	else if (ft_strchr("S", flags->type))
		*tl += ft_wputstr(va_arg(ap, wint_t*));
	else if (ft_strchr("s", flags->type))
		return (ft_conv_alpha(va_arg(ap, char*), flags));
	else if (ft_strchr("c", flags->type))
		return (ft_conv_alpha(ft_ctoa(va_arg(ap, wchar_t)), flags));
	else if (ft_strchr("C", flags->type))
		*tl += ft_wputstr(ft_wctoa(va_arg(ap, wint_t)));
	return (NULL);
}

char	*ft_cast_alpha(t_flags *flags, va_list ap, int *tl)
{
	if (flags->fc == INT)
		return (ft_conv_alpha(ft_ctoa((wint_t)va_arg(ap, int)), flags));
	else if (flags->fc == CHAR_PTR || flags->type == 's')
		return (ft_conv_alpha(va_arg(ap, char*), flags));
	else if (flags->fc == WCHAR_T_PTR || flags->type == 'S')
		*tl += ft_wputstr(ft_conv_walpha(va_arg(ap, wint_t*), flags));
	else if (flags->fc == WINT_T || flags->type == 'C')
		*tl += ft_wputstr(ft_conv_walpha(ft_wctoa(va_arg(ap, wchar_t)), flags));
	return (NULL);
}

char	*ft_cast_digit(t_flags *flags, va_list ap)
{
	if (flags->fc == S_CHAR)
		return (ft_conv_num(ft_itoa(va_arg(ap, int)), flags));
	else if (flags->fc == SHORT_I)
		return (ft_conv_num(ft_itoa(va_arg(ap, int)), flags));
	else if (flags->fc == U_LONG_I)
		return (ft_conv_num(ft_itoa(va_arg(ap, long)), flags));
	else if (flags->fc == U_LONG_LONG_I)
		return (ft_conv_num(ft_itoa(va_arg(ap, long)), flags));
	else if (flags->fc == U_INTMAX_T)
		return (ft_conv_num(ft_itoa((long)va_arg(ap, uintmax_t)), flags));
	return (NULL);
}

char	*ft_cast_digit_base(t_flags *flag, va_list ap, int base)
{
	if (flag->fc == S_CHAR)
		return (ft_conv_num(ft_uitoa_b(va_arg(ap, unsigned int), base), flag));
	else if (flag->fc == U_SHORT_I)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned int), base), flag));
	else if (flag->fc == U_LONG_I)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned long), base), flag));
	else if (flag->fc == U_LONG_LONG_I)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, unsigned long), base), flag));
	else if (flag->fc == U_INTMAX_T)
		return (ft_conv_num(ft_ulitoa_b(va_arg(ap, uintmax_t), base), flag));
	return (NULL);
}

char	*ft_cast_arg(t_flags *flags, va_list ap, int *tl)
{
	int	base;

	base = 10;
	if (flags->type == 'o')
		base = 8;
	else if (flags->type == 'x' || flags->type == 'X')
		base = 16;
	else if (ft_strchr("difFeEgGaA", flags->type))
		base = 10;
	if ((!flags->ic && !ft_strchr("sScC", flags->type)) ||
	ft_strchr("p", flags->type))
		return (ft_cast_type(flags, ap, base, tl));
	else if ((flags->fc >= INT && flags->fc <= WCHAR_T_PTR))
		return (ft_cast_alpha(flags, ap, tl));
	else if (flags->fc >= S_CHAR && flags->fc <= INTMAX_T)
		return (ft_cast_digit(flags, ap));
	else if (flags->fc >= U_INT && flags->fc <= U_INTMAX_T)
		return (ft_cast_digit_base(flags, ap, base));
	else if (flags->fc == SIZE_T && ft_strchr("di", flags->type))
		return (ft_conv_num(ft_itoa((long)va_arg(ap, size_t)), flags));
	else if (flags->fc == SIZE_T && ft_strchr("uoxX", flags->type))
		return (ft_conv_num(ft_uitoa_b((long)va_arg(ap, size_t), base), flags));
	return (NULL);
}
