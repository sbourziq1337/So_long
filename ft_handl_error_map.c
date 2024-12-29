/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_error_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:56:24 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:56:30 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_last_wall(char **res)
{
	if (check_number(*res) == 1)
	{
		free(*res);
		ft_printf("Error in your map (last wall)\n");
		exit(1);
	}
}

void	ft_count_char(char *res, t_count *check)
{
	check->check_p += ft_check_char(res, 'P');
	check->check_e += ft_check_char(res, 'E');
	check->check_n += ft_check_char(res, 'N');
	check->check_c += ft_check_char(res, 'C');
}
