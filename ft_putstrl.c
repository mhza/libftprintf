/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaziza <mhaziza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:06 by mhaziza           #+#    #+#             */
/*   Updated: 2017/01/08 19:04:55 by mhaziza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrl(char const *s)
{
	if (!s)
		ft_putstr("(Null)");
	else
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}
