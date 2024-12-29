/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prin_low_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:06:51 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:57:19 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_hex(unsigned int low, char str, int *len)
{
	char	*base;

	if (str == 'x')
	{
		base = "0123456789abcdef";
	}
	else if (str == 'X')
	{
		base = "0123456789ABCDEF";
	}
	if (low >= 16)
	{
		ft_print_hex(low / 16, str, len);
		ft_print_hex(low % 16, str, len);
	}
	else
		ft_putchar(base[low % 16], len);
}
