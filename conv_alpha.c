/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 17:48:07 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ctoa(int c)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

wchar_t	*ft_wctoa(wchar_t c)
{
	wchar_t	*str;

	if ((str = (wchar_t*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c ? c : '\0';
	str[1] = '\0';
	return (str);
}

char	*ft_conv_alpha(char *param, t_flags *sflags)
{
	char	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;

	if (!param)
	{
		final_p = ft_strnew(6);
		final_p = "(null)";
		return (final_p);
	}
	p_len = ft_strlen(param);
	cpy_len = sflags->precision && sflags->precision < p_len ? sflags->precision
	: p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;

	// ft_putstr(" p_len = ");ft_putnbr(p_len);ft_putstr("\n");
	// ft_putstr(" new_len = ");ft_putnbr(new_len);ft_putstr("\n");
	// ft_putstr(" minus = ");ft_putnbr(sflags->minus);ft_putstr("\n");
	// ft_putstr(" width = ");ft_putnbr(sflags->width);ft_putstr("\n");
	// ft_putstr(" cpy_len = ");ft_putnbr(cpy_len);ft_putstr("\n");
	if (sflags->type != '%' && (sflags->space || sflags->hashtag))
		return (NULL);
	if ((final_p = ft_strnew((size_t)new_len)) == NULL)
		return (NULL);
	i = 0;
	while (!sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[i] = sflags->zero ? '0' : ' ';
		i++;
	}
	ft_strncpy(final_p + i, param, cpy_len);
	while (sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[cpy_len + i] = ' ';
		i++;
	}
	if (sflags->type == 'c' && !p_len && new_len > 1)
	{
		if (sflags->width > 1)
			sflags->emptyc = 1;
		return (final_p + 1);
	}
	return (final_p);
}

wchar_t	*ft_conv_walpha(wchar_t *param, t_flags *sflags)
{
	wchar_t	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;

	if (!param)
		return (NULL);
	p_len = ft_wbyteslen(param);
	cpy_len = sflags->precision && sflags->precision < p_len ?
	sflags->precision : p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	// ft_putstr(" p_len = ");ft_putnbr(p_len);ft_putstr("\n");
	// ft_putstr(" new_len = ");ft_putnbr(new_len);ft_putstr("\n");
	// ft_putstr(" minus = ");ft_putnbr(sflags->minus);ft_putstr("\n");
	// ft_putstr(" precision = ");ft_putnbr(sflags->precision);ft_putstr("\n");
	// ft_putstr(" width = ");ft_putnbr(sflags->width);ft_putstr("\n");
	// ft_putstr(" cpy_len = ");ft_putnbr(cpy_len);ft_putstr("\n");
	if (sflags->space || sflags->hashtag)
		return (NULL);
	if ((final_p = (wchar_t*)malloc(sizeof(final_p) * new_len)) == NULL)
		return (NULL);
	i = 0;
	while (!sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[i] = sflags->zero ? '0' : ' ';
		i++;
	}
	if (cpy_len)
	{
		ft_wstrncpy(final_p + i, param, cpy_len);

	}
	else
	{
		write(1, "\0", 1);
		return (param);
	}
	while (sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[ft_wstrlen(param) + i] = ' ';
		i++;
	}

	if (sflags->type == 'C' && !p_len)
			sflags->emptyc = 1;
	return (final_p);
}
