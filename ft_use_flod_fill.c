/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_use_flod_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:58:16 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:58:18 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_exit(char **map, t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->height - 1)
	{
		y = 0;
		while (y < data->width)
		{
			if (map[x][y] == 'P' || map[x][y] == 'E' || map[x][y] == 'C'
				|| map[x][y] == 'N')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

int	ft_check_exit1(char **map, t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->height - 1)
	{
		y = 0;
		while (y < data->width)
		{
			if (map[x][y] == 'X')
				return (1);
			if (x > 0)
			{
				if (map[x + 1][y] == '1' && map[x - 1][y] == '1' && map[x][y
					+ 1] == '1' && map[x][y - 1] == '1')
					return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char	**ft_flod_fill(int x, int y, char **str, t_mlx *data)
{
	if (x < data->height && str[x + 1][y] != '1' && str[x + 1][y] != 'X')
	{
		str[x + 1][y] = 'X';
		ft_flod_fill(x + 1, y, str, data);
	}
	if (x < data->height && str[x - 1][y] != '1' && str[x - 1][y] != 'X')
	{
		str[x - 1][y] = 'X';
		ft_flod_fill(x - 1, y, str, data);
	}
	if (x < data->height && str[x][y + 1] != '1' && str[x][y + 1] != 'X')
	{
		str[x][y + 1] = 'X';
		ft_flod_fill(x, y + 1, str, data);
	}
	if (x < data->height && str[x][y - 1] != '1' && str[x][y - 1] != 'X')
	{
		str[x][y - 1] = 'X';
		ft_flod_fill(x, y - 1, str, data);
	}
	return (str);
}

int	ft_check_map(char **str, t_mlx *data)
{
	char	**my_map;
	int		x;
	int		y;

	x = 0;
	while (x < data->height - 1)
	{
		y = 0;
		while (y < data->width)
		{
			if (str[x][y] == 'P')
			{
				my_map = ft_flod_fill(x, y, str, data);
			}
			y++;
		}
		x++;
	}
	if (ft_check_exit1(my_map, data) == 1)
	{
		if (ft_check_exit(my_map, data) == 1)
			return (1);
	}
	return (0);
}
