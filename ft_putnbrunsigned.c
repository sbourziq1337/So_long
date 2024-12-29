/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:36 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:57:44 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbrunsigned(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbrunsigned(nb / 10, len);
		ft_putnbrunsigned(nb % 10, len);
	}
	else
		ft_putchar(nb + 48, len);
}
