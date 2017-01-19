/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrncpyp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:03:40 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/19 18:34:36 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrncpyp(wchar_t *dest, const wchar_t *src, size_t n)
{
	unsigned int	i;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	while (ibytes <= n && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16) && ibytes + 1 <= n)
		{
			dest[i] = src[i];
			ibytes+=1;
		}
		else if (src[i] <= ft_atoi_base("7FF", 16) && ibytes + 2 <= n)
		{
			dest[i] = src[i];
			ibytes+=2;
		}
		else if (src[i] <= ft_atoi_base("FFFF", 16) && ibytes + 3 <= n)
		{
			dest[i] = src[i];
			ibytes+=3;
		}
		else if (src[i] <= ft_atoi_base("10FFFF", 16) && ibytes + 4 <= n)
		{
			dest[i] = src[i];
			ibytes+=4;
		}
		i++;
	}
	while (i <= n)
		dest[i++] = '\0';
	return (dest);
}
