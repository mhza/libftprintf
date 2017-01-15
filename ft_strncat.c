/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:06:01 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/15 01:08:20 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	ft_putstr("STRNCAT\n");
	ft_putstr("src : ");
	//ft_putstr(src);
	ft_putstr("\n");
	ft_putstr("dest : ");
	ft_putstr(dest);
	ft_putstr("\n");
	ft_putstr("size : ");
	ft_putnbr((int)n);
	ft_putstr("\n");
	i = ft_strlen(dest);
	j = 0;
	while (n-- && src && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
