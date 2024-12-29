/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:55:36 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:55:40 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_mlx *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->str[i])
	{
		temp = data->str[i];
		data->str[i] = data->str[i + 1];
		free(temp);
		i++;
	}
	system("leaks so_long");
}

void	ft_free_and_destroy(t_mlx *data)
{
	int		i;
	char	*temp;
	char	**map;

	map = data->str;
	i = 0;
	while (map[i])
	{
		temp = map[i];
		map[i] = map[i + 1];
		free(temp);
		i++;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->str);
	exit(0);
}
