/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_bytes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:31:44 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 11:32:02 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_nb_bytes(wchar_t *src, int n)
{
	unsigned int	i;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	while (i < n && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16))
			ibytes += 1;
		else if (src[i] <= ft_atoi_base("7FF", 16))
			ibytes += 2;
		else if (src[i] <= ft_atoi_base("FFFF", 16))
			ibytes += 3;
		else if (src[i] <= ft_atoi_base("10FFFF", 16))
			ibytes += 4;
		i++;
	}
	return (ibytes);
}
