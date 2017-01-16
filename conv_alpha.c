/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/16 04:23:27 by mhaziza          ###   ########.fr       */
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
	p_len = (int)ft_strlen(param);

	cpy_len = sflags->precision && sflags->precision < p_len ? sflags->precision
	: p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->plus || sflags->space || sflags->zero || sflags->hashtag)
		return (NULL);
	if ((final_p = ft_strnew((size_t)new_len)) == NULL)
		return (NULL);
	i = 0;
	while (!sflags->minus && new_len > cpy_len && i < sflags->width - cpy_len)
	{
		final_p[i] = ' ';
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

wchar_t	*ft_wctoa(wchar_t c)
{
	wchar_t	*str;

	if ((str = (wchar_t*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

wchar_t	*ft_conv_walpha(wchar_t *param, t_flags *sflags)
{
	wchar_t	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;
// 	ft_putstr("ft_conv_walpha ");
// 	ft_wputstr(param);
// ft_putstr("\n");
	p_len = ft_wstrlen(param);
	cpy_len = sflags->precision && sflags->precision < p_len ?
	sflags->precision : p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->plus || sflags->space || sflags->zero || sflags->hashtag)
		return (NULL);
	if ((final_p = (wchar_t*)malloc(sizeof(final_p) * new_len)) == NULL)
		return (NULL);
	i = 0;
	while (new_len > cpy_len && i + 1 < sflags->width && !sflags->minus)
	{
		final_p[i] = ' ';
		i++;
	}
 	ft_wstrncpy(final_p + i, param, cpy_len);
	ft_putnbr(new_len);
ft_putstr("\n");
  	ft_wputstr(param);
  ft_putstr("\n");
  ft_wputstr(final_p);
ft_putstr("\n");
	return (final_p);
}
