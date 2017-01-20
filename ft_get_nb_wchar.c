/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:31:09 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/20 11:31:27 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_nb_wchar(wchar_t *src, int n)
{
	unsigned int	i;
	unsigned int	ibytes;

	i = 0;
	ibytes = 0;
	while (ibytes < n && src[i])
	{
		if (src[i] <= ft_atoi_base("7F", 16) && ibytes + 1 <= n)
			ibytes += 1;
		else if (src[i] <= ft_atoi_base("7FF", 16) && ibytes + 2 <= n)
			ibytes += 2;
		else if (src[i] <= ft_atoi_base("FFFF", 16) && ibytes + 3 <= n)
			ibytes += 3;
		else if (src[i] <= ft_atoi_base("10FFFF", 16) && ibytes + 4 <= n)
			ibytes += 4;
		else
			return (i);
		i++;
	}
	return (i);
}
