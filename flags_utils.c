/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:33:23 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/18 19:37:25 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//
// int		ft_check_flags(char *flags, int conv, int dot)
// {
// 	if (flags[0] && ft_isdigit(flags[0]))
// 		return (ft_check_flags(flags + 1, conv, dot));
// 	if (flags[0] && flags[0] == '.' && !dot)
// 		return (ft_check_flags(flags + 1, conv, 1));
// 	if (flags[0] && !conv && (ft_strchr("zj", flags[0]) || ft_isdigit(flags[0])))
// 		return (ft_check_flags(flags + 1, 1, dot));
// 	if (flags[0] && !conv && flags[1] && ft_strchr("hl", flags[0]) && flags[1] == flags[0])
// 		return (ft_check_flags(flags + 2, 1, dot));
// 	if (flags[0] && !conv && flags[1] && ft_strchr("hl", flags[0]) && flags[1] != flags[0])
// 		return (ft_check_flags(flags + 1, 1, dot));
// 	if (flags[0] && ft_strchr("sSpdDioOuUxXcCgG", flags[0]) && !flags[1])
// 		return (1);
// 	return (0);
// }

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
	if (!(flags = (char*)malloc(first + 1)))
		return (NULL);
	return (ft_strncpy(flags, str, first));
}

void	typeformat(t_flags *e)
{
	if (ft_strchr("di", e->type))
		e->fc = e->ic;
	if (ft_strchr("uoxX", e->type))
		e->fc = e->ic + 10;
	if (ft_strchr("fFeEgGaA", e->type))
		e->fc = DOUBLE;
	if (e->type == 'c' && e->ic == 0)
		e->fc = INT;
	if ((e->type == 'c' && e->ic == 3) || e->type == 'C')
		{
			e->type = 'C';
			e->fc = WINT_T;
		}
	if (e->type == 's' && e->ic == 0)
		e->fc = CHAR_PTR;
	if ((e->type == 's' && e->ic == 3) || e->type == 'S')
		{
			e->type = 'S';
			e->fc = WCHAR_T_PTR;
		}
	if (e->type == 'p' && e->ic == 0)
		e->fc = VOID_PTR;
}

void	ft_special_flags(char *str, t_flags *sflags)
{
	if (!strncmp(str, "ll", 2))
	{
		sflags->ic = LL;
		str = str + 1;
	}
	else if (!strncmp(str, "hh", 2))
	{
		sflags->ic = HH;
		str = str + 1;
	}
	else if (!strncmp(str, "h", 1))
		sflags->ic = H;
	else if (!strncmp(str, "l", 1))
		sflags->ic = L;
	else if (!strncmp(str, "j", 1))
		sflags->ic = J;
	else if (!strncmp(str, "z", 1))
		sflags->ic = Z;
}

void	ft_set_flags(t_flags *sflags, char *flags, int len)
{
	sflags->type = flags[len - 1];
	if (sflags->type == 'U')
	{
		sflags->type = 'u';
		sflags->ic = L;
	}
	if (sflags->type == 'D')
	{
		sflags->type = 'd';
		sflags->ic = L;
	}
	if (sflags->type == 'O')
	{
		sflags->type = 'o';
		sflags->ic = L;
	}
	sflags->flags = flags;
	sflags->flags_len = ft_strlen(flags);
	if (ft_strchr(sflags->flags, 'j'))
		sflags->ic = J;
	while (*flags)
	{
		if (*flags == '#')
			sflags->hashtag = 1;
		if (*flags == '0' && !sflags->width && !sflags->precision)
			sflags->zero = 1;
		if (*flags == '-')
			sflags->minus = 1;
		if (*flags == '+')
			sflags->plus = 1;
		if (*flags == ' ')
			sflags->space = 1;
		if (ft_isdigit(*flags) && !sflags->width)
			sflags->width = ft_atoi(flags) > 0 ? ft_atoi(flags) : 0;
		if (*flags == '.')
		{
			sflags->dot = 1;
			sflags->precision = ft_atoi(++flags);
		}
		if (!sflags->ic)
			ft_special_flags(flags, sflags);
		flags++;
	}
	if (sflags->ic != J)
		typeformat(sflags);
}
