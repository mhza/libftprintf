/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:50:15 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 18:11:05 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_pluspace(t_arg *arg, t_flags *f)
{
	char	*prefix;

	if (f->space)
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, ' ', 1);
	}
	if (f->plus && f->type != 'u')
	{
		prefix = ft_strnew(1);
		ft_memset(prefix, '+', 1);
	}
	arg->prefix = prefix;
}

void	ft_if_ox(t_arg *arg, t_flags *f)
{
	char	*prefix;
	size_t	pre_len;
	int		is_nul;

	pre_len = 0;
	is_nul = !ft_strcmp(arg->param, "0");
	if (f->type == 'X' || f->type == 'x' || f->type == 'p')
		pre_len = !is_nul || f->type == 'p' ? 2 : 0;
	else
		pre_len = is_nul ? 0 : 1;
	prefix = ft_strnew(pre_len);
	if (f->hashtag || f->type == 'p')
		prefix = ft_strncpy(prefix, "0x", pre_len);
	if (f->type == 'X')
	{
		arg->param = ft_toupperstr(arg->param);
		prefix = ft_toupperstr(prefix);
	}
	arg->prefix = prefix;
	if (!ft_strcmp(arg->param, "0") && f->type == 'o' && (!f->precision && f->dot && !f->hashtag))
		arg->param = "";
}

void	ft_if_precision(t_arg *arg, t_flags *f)
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
	new_len = (int)p_len > f->precision ? p_len : (size_t)f->precision;
	if (new_len - p_len)
	{
		tmp = ft_strnew(new_len);
		ft_memset(tmp, '0', new_len - p_len);
		ft_strncat(tmp, arg->param, p_len);
		arg->param = tmp;
	}
}

void	ft_if_width(t_arg *arg, t_flags *f)
{
	int		to_add;
	size_t	cur_len;
	size_t	pre_len;
	char	*tmp;

	if (*arg->param == '-')
	{
		arg->param = arg->param + 1;
		arg->prefix = ft_strnew(1);
		ft_memset(arg->prefix, '-', 1);
	}
	pre_len = ft_strlen(arg->prefix);
	cur_len = pre_len + ft_strlen(arg->param);
	to_add = (int)f->width - (int)cur_len;
	if (to_add > 0)
	{
		if (f->minus)
		{
			arg->suffix = ft_strnew((size_t)to_add);
			ft_memset(arg->suffix, ' ', (size_t)to_add);
		}
		else
		{
			tmp = ft_strnew((size_t)to_add + pre_len);
			if (f->zero && !f->precision)
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

char	*ft_conv_num(char *param, t_flags *f)
{
	size_t	final_len;
	size_t	pre_len;
	size_t	p_len;
	char	*final_p;
	t_arg	*arg;

	if (!ft_strchr("poxX", f->type) && !f->hashtag && !f->zero && !f->dot &&
	!f->minus && !f->plus && !f->space && !f->width && !f->precision)
		return (param);
	arg = ft_memalloc(sizeof(arg));
	arg->param = ft_memalloc(sizeof(char) * (ft_strlen(param) + 1));
	arg->prefix = ft_memalloc(sizeof(char) + 1);
	arg->suffix = ft_memalloc(sizeof(char) + 1);
	arg->param = param;
	if (ft_strchr("poxX", f->type))
		ft_if_ox(arg, f);
	else if (*arg->param != '-' && f->type != 'u' && (f->plus || f->space))
		ft_if_pluspace(arg, f);
	if (f->precision)
		ft_if_precision(arg, f);
	if (!ft_strcmp(arg->param, "0") && f->dot && !f->precision &&
	(!f->fc || f->fc == U_INT))
		arg->param = "";
	if (f->width)
		ft_if_width(arg, f);
	pre_len = ft_strlen(arg->prefix);
	p_len = ft_strlen(arg->param);
	final_len = pre_len + p_len + ft_strlen(arg->suffix);
	final_p = ft_strnew(final_len);
	ft_strncpy(final_p, arg->prefix, pre_len);
	ft_strncpy(final_p + pre_len, arg->param, p_len);
	ft_strncpy(final_p + pre_len + p_len, arg->suffix, ft_strlen(arg->suffix));
	return (final_p);
}
