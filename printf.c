/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:45:32 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 10:58:43 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_flags(char *str)
{
	char	*next_type;
	char	*flags;
	int		position;
	int		first;
	int		i;

	i = -1;
	position = -1;
	first = -1;
	while (LTYPES[++i])
	{
		if ((next_type = ft_strchr(str, LTYPES[i])) && (first < 0 ||
			next_type - str < first))
			first = next_type - str + 1;
	}
	if (first == -1)
		return (NULL);
	if (!(flags = (char*)malloc(first + 1)))
		return (NULL);
	return (ft_strncpy(flags, str, first));
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	char	*flags;
	int		*total_length;
	int		len;
	t_flags	sflags;

	if ((total_length = ft_memalloc(sizeof(total_length))) == NULL)
		return (-1);
	*total_length = 0;
	va_start(ap, str);
	while (str && *str && ft_strchr(str, '%'))
	{
		if ((str = ft_print_str(str, total_length) + 1))
		{
			if ((flags = ft_get_flags(str)))
			{
				if (ft_strchr(flags, '*'))
					return (-1);
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
