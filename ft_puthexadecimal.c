/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:34:13 by sbourziq          #+#    #+#             */
/*   Updated: 2023/11/26 12:22:23 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_print_hexw(unsigned long int decimal, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (decimal >= 16)
	{
		ft_print_hexw(decimal / 16, len);
		ft_print_hexw(decimal % 16, len);
	}
	else
		ft_putchar(base[decimal % 16], len);
}

void	ft_hexadecimal(unsigned long int decimal, int *len)
{
	ft_putstr("0x", len);
	ft_print_hexw(decimal, len);
}
