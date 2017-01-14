/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:48:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/12 17:55:12 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putwchar2(wchar_t c)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};
	unsigned char			byte;

	byte = 0;
	if (c <= ft_atoi_base("FFFF", 16))
	{
		byte = mask[2] + (c >> 12);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 6) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
	}
	else if (c <= ft_atoi_base("10FFFF", 16))
	{
		byte = mask[3] + (c >> 18);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 12) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + ((c >> 6) & mask[4]);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
	}
}

void		ft_wputchar(wchar_t c)
{
	static unsigned short	mask[] = {128, 192, 224, 240, 63};
	unsigned char			byte;

	byte = 0;
	if (c <= ft_atoi_base("7F", 16))
		write(1, &c, 1);
	else if (c <= ft_atoi_base("7FF", 16))
	{
		byte = mask[1] + (c >> 6);
		write(1, &byte, 1);
		byte = mask[0] + (c & mask[4]);
		write(1, &byte, 1);
	}
	else
		ft_putwchar2(c);
}
