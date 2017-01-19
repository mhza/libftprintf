/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 16:43:07 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_print_str(char *str, int *tl)
{
	char	*next;

	if ((next = ft_strchr(str, '%')) == NULL)
		*tl += ft_wputstr((int*)str);
	else if (next)
	{
		*tl += next - str;
		write(1, str, next - str);
	}
	return (next);
}

char	*ft_print_params(char *str, t_flags *sflags, va_list ap, int *tl)
{
	char	type;
	char	*param;
	int		i;

	i = 0;
	type = sflags->type;
	if ((type == '%' && sflags->percent == -1) || sflags->is_invalid)
	{
		sflags->type = '%';
		while (i < sflags->flags_len && str[i])
		{
			if (ft_strchr("+-. ", str[i]))
				i++;
			else if (ft_isdigit(str[i]) && (sflags->width || sflags->precision))
				i++;
			else
			{
				param = ft_conv_alpha(ft_ctoa(str[i]), sflags);
				*tl += ft_putstr(param);
				if (str + i + 2)
					return (str + i + 2);
				else
					return (NULL);
			}
		}

	}
	else if (type == '%' && !sflags->percent)
	{
		//return (NULL);
		sflags->space = 0;
		param = ft_conv_alpha(ft_ctoa(type), sflags);
	}
	else
		param = ft_cast_arg(sflags, ap, tl);
	if ((!ft_strlen(param) || sflags->emptyc) && ft_strchr("c", type))
	{
		if (sflags->minus)
			write(1, "\0", 1);
		*tl += ft_putstr(param) + 1;
		if (!sflags->minus)
			write(1, "\0", 1);
	}
	else if (param && !ft_strchr("SC", type))
		*tl += ft_putstr(param);
	return (str + sflags->flags_len + 1);
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	char	*flags;
	int		*total_length;
	int		len;
	t_flags	sflags;

	total_length = (int*)malloc(sizeof(int));
	*total_length = 0;
	va_start(ap, str);
	while (str && *str && ft_strchr(str, '%'))
	{
		if ((str = ft_print_str(str, total_length) + 1))
		{	if ((flags = ft_get_flags(str)))
			{
				ft_bzero(&sflags, sizeof(t_flags));
				len = ft_strlen(flags);
				if (!len)
					return (0);
				if (len >= 1)
					ft_set_flags(&sflags, flags, len);
				str = ft_print_params(str, &sflags, ap, total_length) - 1;
				ft_bzero(flags, ft_strlen(flags));
			}
			else if (ft_strlen(str) > 1)
			{
				ft_bzero(&sflags, sizeof(t_flags));
				sflags.type = '%';
				ft_set_flags(&sflags, str, ft_strlen(str));
				str = ft_print_params(str, &sflags, ap, total_length) - 1;
			}
		}
	}
	if (str)
		*total_length += ft_putstr(str);
	va_end(ap);
	return (*total_length);
}
