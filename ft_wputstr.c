/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/14 12:05:16 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wputstr(const wchar_t *s)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	else
	{
		while (++i < (int)ft_wstrlen(s))
			ft_wputchar(s[i]);
		return (ft_wstrlen(s));
	}
}
