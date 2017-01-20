/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 11:28:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ctoa(int c)
{
	char	*str;

	if ((str = (char*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

wchar_t		*ft_wctoa(wchar_t c)
{
	wchar_t	*str;

	if ((str = (wchar_t*)malloc(sizeof(c) + 1)) == NULL)
		return (NULL);
	str[0] = c ? c : '\0';
	str[1] = '\0';
	return (str);
}

char		*ft_conv_alpha(char *param, t_flags *sflags)
{
	char	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;

	if (!param && !sflags->width)
	{
		final_p = ft_strnew(6);
		final_p = "(null)";
		return (final_p);
	}
	p_len = ft_strlen(param);
	cpy_len = sflags->dot && sflags->precision < p_len && sflags->type != '%' ?
	sflags->precision
	: p_len;
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->type != '%' && (sflags->hashtag))
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

int			ft_get_nb_wchar(wchar_t *src, int n)
{
	unsigned int	i;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	while (ibytes < n && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16) && ibytes + 1 <= n)
			ibytes += 1;
		else if (src[i] <= ft_atoi_base("7FF", 16) && ibytes + 2 <= n)
			ibytes += 2;
		else if (src[i] <= ft_atoi_base("FFFF", 16) && ibytes + 3 <= n)
			ibytes += 3;
		else if (src[i] <= ft_atoi_base("10FFFF", 16) && ibytes + 4 <= n)
			ibytes += 4;
		else
			return (i);
		i++;
	}
	return (i);
}

int			ft_get_nb_bytes(wchar_t *src, int n)
{
	unsigned int	i;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	while (i < n && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16))
			ibytes += 1;
		else if (src[i] <= ft_atoi_base("7FF", 16))
			ibytes += 2;
		else if (src[i] <= ft_atoi_base("FFFF", 16))
			ibytes += 3;
		else if (src[i] <= ft_atoi_base("10FFFF", 16))
			ibytes += 4;
		i++;
	}
	return (ibytes);
}

wchar_t		*ft_conv_walpha(wchar_t *param, t_flags *sflags)
{
	wchar_t	*final_p;
	int		new_len;
	int		cpy_len;
	int		p_len;
	int		i;

	if (!param)
		return (NULL);
	if (sflags->dot)
		cpy_len = ft_get_nb_wchar(param, sflags->precision);
	else
		cpy_len = ft_wbyteslen(param);
	p_len = ft_get_nb_bytes(param, cpy_len);
	new_len = sflags->width > cpy_len ? sflags->width : cpy_len;
	if (sflags->hashtag)
		return (NULL);
	if ((final_p = (wchar_t*)malloc(sizeof(final_p) * new_len)) == NULL)
		return (NULL);
	i = 0;
	while (!sflags->minus && new_len > cpy_len && i < sflags->width - p_len)
	{
		final_p[i] = sflags->zero ? '0' : ' ';
		i++;
	}
	if (cpy_len || (sflags->type == 'S' && (sflags->dot || sflags->width)))
		ft_wstrncpy(final_p + i, param, cpy_len);
	else
	{
		if (sflags->type == 'C')
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
