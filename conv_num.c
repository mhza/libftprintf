/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/15 20:31:56 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_pluspace(t_arg *arg, t_flags *flags)
{
	char	*prefix;

	if (flags->plus && flags->type != 'u')
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, '+', 1);
	}
	if (flags->space )
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, ' ', 1);
	}
	arg->prefix = prefix;
}

void	ft_if_oxX(t_arg *arg, t_flags *flags)
{
	char	*prefix;
	size_t	pre_len;

	pre_len = 0;
	if (flags->type == 'X' || flags->type == 'x')
		pre_len = ft_strcmp(arg->param, "0") ? 0 : 2;
	else
		pre_len = 1;
	prefix = ft_strnew(pre_len);
	if (flags->hashtag)
		prefix = ft_strncpy(prefix, "0x", pre_len);
	if (flags->type == 'X')
	{
		arg->param = ft_toupperstr(arg->param);
		prefix = ft_toupperstr(prefix);
	}
	arg->prefix = prefix;
}

void	ft_if_precision(t_arg *arg, t_flags *flags)
{
	size_t	new_len;
	size_t	p_len;
	char	*tmp;

	if (*arg->param == '-')
	{
		arg->param = arg->param + 1;
		arg->prefix = ft_strnew(1);
		ft_memset(arg->prefix, '-', 1);
	}
	p_len = ft_strlen(arg->param);
	new_len = (int)p_len > flags->precision ? p_len : (size_t)flags->precision;
	if (new_len - p_len)
	{
		tmp = ft_strnew(new_len);
		ft_memset(tmp, '0', new_len - p_len);
		ft_strncat(tmp, arg->param, p_len);
		arg->param = tmp;
	}
}

void	ft_if_width(t_arg *arg, t_flags *flags)
{
	int	to_add;
	size_t	cur_len;
	size_t	pre_len;
	char	*tmp;
	int		is_neg;

	if (*arg->param == '-')
	{
		arg->param = arg->param + 1;
		arg->prefix = ft_strnew(1);
		ft_memset(arg->prefix, '-', 1);
	}
	pre_len = ft_strlen(arg->prefix);
	cur_len = pre_len + ft_strlen(arg->param);
	to_add = (int)flags->width - (int)cur_len;
	if (to_add > 0)
	{
		if (flags->minus)
		{
			arg->suffix = ft_strnew((size_t)to_add);
			ft_memset(arg->suffix, ' ', (size_t)to_add);
		}
		else
		{
			tmp = ft_strnew((size_t)to_add + pre_len);
			if (flags->zero)
			{
				ft_strncpy(tmp, arg->prefix, pre_len);
				ft_memset(tmp + pre_len, '0', to_add);
			}
			else
			{
				ft_memset(tmp, ' ', to_add);
				ft_strncpy(tmp + to_add, arg->prefix, pre_len);
			}
			arg->prefix = tmp;
		}
	}
}

char	*ft_conv_num(char *param, t_flags *flags)
{
	size_t	final_len;
	size_t	pre_len;
	size_t	par_len;
	char	*final_p;
	t_arg	*arg;

	if (!flags->hashtag && !flags->zero && !flags->minus && !flags->plus &&
	!flags->space && !flags->width && !flags->precision)
		return (param);
	arg = ft_memalloc(sizeof(arg));
	arg->param = ft_memalloc(sizeof(char) * (ft_strlen(param) + 1));
	arg->prefix = ft_memalloc(sizeof(char) + 1);
	arg->suffix = ft_memalloc(sizeof(char) + 1);
	arg->param = param;
	if (flags->hashtag && ft_strchr("oxX", flags->type))
		ft_if_oxX(arg, flags);
	else if (*arg->param != '-' && (flags->plus || flags->space))
		ft_if_pluspace(arg, flags);
	if (flags->precision)
		ft_if_precision(arg, flags);
	if (flags->width)
		ft_if_width(arg, flags);
	pre_len = ft_strlen(arg->prefix);
	par_len = ft_strlen(arg->param);
	final_len =  pre_len + par_len + ft_strlen(arg->suffix);
	final_p = ft_strnew(final_len);
	ft_strncpy(final_p, arg->prefix, pre_len);
	ft_strncpy(final_p + pre_len, arg->param, par_len);
	ft_strncpy(final_p + pre_len + par_len, arg->suffix, ft_strlen(arg->suffix));
	return (final_p);
}
