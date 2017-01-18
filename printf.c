/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/18 21:18:41 by mhaziza          ###   ########.fr       */
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

	type = sflags->type;
	if (type == '%')
	{
		return (NULL);
		// sflags->space = 0;
		// param = ft_conv_alpha(ft_ctoa(type), sflags);
	}
	else
		param = ft_cast_arg(sflags, ap, tl);
	if (param && !ft_strchr("SC", type))
		*tl += ft_putstr(param);
	if ((!ft_strlen(param) || sflags->emptyc) && sflags->type == 'c')
		*tl += 1;
	return (str + sflags->flags_len + 1);
}

char	*ft_pp_convers(char *str, char *flags, va_list ap, int *tl)
{
	int		len;
	t_flags	sflags;

	ft_bzero(&sflags, sizeof(t_flags));
	len = ft_strlen(flags);
	if (!len)
		return (NULL);
	if (len >= 1)
		ft_set_flags(&sflags, flags, len);
	return (ft_print_params(str, &sflags, ap, tl));
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	char	*flags;
	int		*total_length;

	total_length = (int*)malloc(sizeof(int));
	*total_length = 0;
	va_start(ap, str);
	while (str && *str && ft_strchr(str, '%'))
	{
		if ((str = ft_print_str(str, total_length) + 1))
			if ((flags = ft_get_flags(str)))
			{
				str = ft_pp_convers(str, flags, ap, total_length) - 1;
				ft_bzero(flags, ft_strlen(flags));
			}
	}
	if (str)
		*total_length += ft_putstr(str);
	va_end(ap);
	return (*total_length);
}
