/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:11:00 by sbourziq          #+#    #+#             */
/*   Updated: 2023/11/29 11:48:07 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_creat(va_list dest, const char str, int	*len)
{
	if (str == 'c')
		ft_putchar(va_arg(dest, int), len);
	else if (str == 's')
		ft_putstr(va_arg(dest, char *), len);
	else if (str == 'p')
		ft_hexadecimal(va_arg(dest, unsigned long), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(dest, int), len);
	else if (str == 'u')
		ft_putnbrunsigned(va_arg(dest, unsigned long), len);
	else if (str == 'x')
		ft_print_hex(va_arg(dest, unsigned int), str, len);
	else if (str == 'X')
		ft_print_hex(va_arg(dest, unsigned int), str, len);
	else if (str == '%')
		ft_putchar(str, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (str[i] == '\0')
				return (len);
			ft_creat(args, str[i], &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
