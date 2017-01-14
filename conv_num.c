/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/14 12:37:24 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conv_num(char *param_a, t_flags *sflags)
{
	char	*final_p;
	//char	*param_a;
	int		p_len;
	char	type;

	// if (type == 'o')
	// 	param_a = ft_uitoa_b(param, 8);
	// if (type == 'x')
	// 	param_a = ft_uitoa_b(param, 16);
	if (sflags->type == 'X')
		param_a = ft_toupperstr(param_a);
	// if (ft_strchr("uidEef", type))
	// 	param_a = type == 'u' ? ft_itoa(ABS(param)) : ft_itoa(param);
	type = sflags->type;
	p_len = ft_strlen(param_a);
	if ((final_p = (char*)malloc(p_len + 2)) == NULL)
		return (NULL);
	if (sflags->hashtag && ft_strchr("oxX", type))
	{
		final_p[0] = '0';
		if (type == 'o')
			ft_strncpy(final_p + 1, param_a, ft_strlen(param_a));
		else
		{
			final_p[1] = type;
			ft_strncpy(final_p + 2, param_a, ft_strlen(param_a));
		}
	}
	else if (sflags->plus && !ft_strchr("oxX", type) && !ft_strchr(param_a, '-'))
	{
		final_p[0] = '+';
		ft_strncpy(final_p + 1, param_a, ft_strlen(param_a));
	}
	else if (sflags->space && !sflags->plus && !ft_strchr(param_a, '-') && !sflags->precision)
	{
		final_p[0] = ' ';
		ft_strncpy(final_p + 1, param_a, ft_strlen(param_a));
	}
	else
		ft_strncpy(final_p, param_a, ft_strlen(param_a));
	if (sflags->precision || sflags->width)
		return (ft_man_width(final_p, sflags));
	else
		return (final_p);
}

char	*ft_man_width(char *param, t_flags *sflags)
{
	char	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;

	i = -1;
	p_len = ft_strlen(param);
	cpy_len = sflags->precision > p_len ? sflags->precision : p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if ((final_p = (char*)malloc(new_len + 1)) == NULL)
		return (NULL);
	if (sflags->width > sflags->precision && sflags->precision > p_len)
		return (ft_man_precision(param, sflags));
	while (++i < sflags->width - cpy_len && (!sflags->minus))
		final_p[i] = sflags->zero && !sflags->precision ? '0' : ' ';
	ft_strncpy(final_p + i, param, cpy_len);
	while (sflags->minus && ++i <= sflags->width - cpy_len)
		final_p[i + cpy_len - 1] = sflags->zero && !sflags->precision ?
		'0' : ' ';
	if (sflags->precision)
		return (ft_man_precision(final_p, sflags));
	return (ft_man_minus(final_p));
}

char	*ft_man_precision(char *param, t_flags *sflags)
{
	int		i;
	char	*final_p;
	int		p_len;
	int		new_len;
	int		is_neg;

	i = -1;
	is_neg = ft_strchr(param, '-') ? 1 : 0;
	p_len = ft_strlen(param);
	new_len = sflags->precision > p_len ? sflags->precision + sflags->space :
	p_len;
	if ((final_p = (char*)malloc(new_len + 1)) == NULL)
		return (NULL);
	if (sflags->space && !++i)
		final_p[0] = ' ';
	if (sflags->width > sflags->precision && sflags->precision > p_len)
	{
		while (++i < sflags->width - sflags->precision)
			final_p[i] = ' ';
		i = -1;
		while (++i < sflags->precision - p_len)
			final_p[sflags->width - sflags->precision + i] = '0';
		i = sflags->width - p_len - 1;
	}
	while (++i < sflags->precision - p_len + is_neg + sflags->space)
		final_p[i] = '0';
	ft_strncpy(final_p + i, param, p_len);
	return (ft_man_minus(final_p));
}

char	*ft_man_minus(char *param)
{
	int		is_neg;

	is_neg = ft_strchr(param, '-') ? ft_strchr(param, '-') - param : 0;
	if (is_neg && ft_strchr(param, '0') &&
	ft_strchr(param, '0') - param < is_neg)
	{
		param[is_neg] = '0';
		param[0] = '-';
	}
	return (param);
}
