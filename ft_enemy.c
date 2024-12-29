/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:41 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:54:45 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_lost(t_mlx *data)
{
	ft_printf("you lost >(｡•́︿•̀｡)\n");
	ft_free_and_destroy(data);
}

void	ft_check_enemy_right(t_mlx *data, int i, int j)
{
	if ((data->str[i][j] == 'P' && data->str[i][j + 1] != '1' && data->str[i][j
			+ 1] == 'E') && (ft_check_c(data) == 1))
		ft_print(data);
	else if ((data->str[i][j] == 'P' && data->str[i][j + 1] != '1'
				&& data->str[i][j + 1] == 'N'))
	{
		ft_print_lost(data);
	}
}

void	ft_check_enemy_left(t_mlx *data, int i, int j)
{
	if ((data->str[i][j] == 'P' && data->str[i][j - 1] != '1' && data->str[i][j
			- 1] == 'E') && (ft_check_c(data) == 1))
		ft_print(data);
	else if ((data->str[i][j] == 'P' && data->str[i][j - 1] != '1'
				&& data->str[i][j - 1] == 'N'))
	{
		ft_print_lost(data);
	}
}

void	ft_check_enemy_up(t_mlx *data, int i, int j)
{
	if ((data->str[i][j] == 'P' && data->str[i - 1][j] != '1' && data->str[i
			- 1][j] == 'E') && (ft_check_c(data) == 1))
		ft_print(data);
	else if ((data->str[i][j] == 'P' && data->str[i - 1][j] != '1'
				&& data->str[i - 1][j] == 'N'))
	{
		ft_print_lost(data);
	}
}

void	ft_check_enemy_down(t_mlx *data, int i, int j)
{
	if ((data->str[i][j] == 'P' && data->str[i + 1][j] != '1' && data->str[i
			+ 1][j] == 'E') && (ft_check_c(data) == 1))
		ft_print(data);
	else if ((data->str[i][j] == 'P' && data->str[i + 1][j] != '1'
				&& data->str[i + 1][j] == 'N'))
	{
		ft_print_lost(data);
	}
}
