/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:57:02 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:57:06 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print(t_mlx *data)
{
	ft_printf("you win > (´｡• ᵕ •｡`)\n");
	ft_free_and_destroy(data);
}

void	ft_right(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j] != '\n' && data->str[i][j] != '\0')
		{
			ft_check_enemy_right(data, i, j);
			if (data->str[i][j] == 'P' && data->str[i][j + 1] != '1'
				&& data->str[i][j + 1] != 'E')
			{
				(data->count_moves)++;
				data->str[i][j] = '0';
				data->str[i][++j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_left(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j] != '\n')
		{
			ft_check_enemy_left(data, i, j);
			if (data->str[i][j] == 'P' && data->str[i][j - 1] != '1'
				&& data->str[i][j - 1] != 'E')
			{
				(data->count_moves)++;
				data->str[i][j] = '0';
				data->str[i][j - 1] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_up(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j] != '\n')
		{
			ft_check_enemy_up(data, i, j);
			if (data->str[i][j] == 'P' && data->str[i - 1][j] != '1'
				&& data->str[i - 1][j] != 'E')
			{
				(data->count_moves)++;
				data->str[i][j] = '0';
				data->str[i - 1][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_down(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->str[i + 1])
	{
		j = 0;
		while (data->str[i][j] != '\n')
		{
			ft_check_enemy_down(data, i, j);
			if (data->str[i][j] == 'P' && data->str[i + 1][j] != '1'
				&& data->str[i + 1][j] != 'E')
			{
				(data->count_moves)++;
				data->str[i][j] = '0';
				data->str[++i][j] = 'P';
				return ;
			}
			j++;
		}
		i++;
	}
}
