/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 10:03:00 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 16:59:57 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(const wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (*ws)
	{
		len++;
		ws++;
	}
	return (len);
}
