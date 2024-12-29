/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:55 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:55:01 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_enemy(t_mlx *data, int i, int j, int x)
{
	if (data->str[i][j + 1] == 'P' && x == 1)
		ft_print_lost(data);
	if (data->str[i][j - 1] == 'P' && x == 2)
		ft_print_lost(data);
}

void	ft_speed_right(t_mlx *data, int i, int j)
{
	ft_move_enemy(data, i, j, 1);
	(data->count_enemy_left)++;
	data->str[i][j] = '0';
	data->str[i][j + 1] = 'N';
	if (data->count_enemy_left == 6)
		data->count_enemy_left = 0;
}

void	ft_speed_left(t_mlx *data, int i, int j)
{
	ft_move_enemy(data, i, j, 2);
	(data->count_enemy_left)--;
	data->str[i][j] = '0';
	data->str[i][j - 1] = 'N';
	if (data->count_enemy_left == -7)
		data->count_enemy_left = -1;
}

void	ft_enemy_speed(t_mlx *data, int i, int j, int x)
{
	if (data->count_enemy == 0 && x == 1)
	{
		if (data->str[i][j + 1] != '1' && data->str[i][j + 1] != 'C'
			&& data->str[i][j + 1] != 'E')
			ft_speed_right(data, i, j);
		else
		{
			data->count_enemy = 1;
			data->count_enemy_left = -1;
		}
	}
	else if (data->count_enemy == 1 && x == 1)
	{
		if (data->str[i][j - 1] != '1' && data->str[i][j - 1] != 'C'
			&& data->str[i][j - 1] != 'E')
			ft_speed_left(data, i, j);
		else
		{
			data->count_enemy = 0;
			data->count_enemy_left = 0;
		}
	}
}

void	loaction_enemy(t_mlx *data)
{
	while (data->i < data->height - 1)
	{
		data->j = 0;
		while (data->j < data->width)
		{
			if (data->str[data->i][data->j] == 'N')
			{
				data->x = 1;
				break ;
			}
			(data->j)++;
		}
		if (data->x == 1)
			break ;
		(data->i)++;
	}
}
