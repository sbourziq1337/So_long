/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilbx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:56:44 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:56:49 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handl_input(int keycode, t_mlx *data)
{
	ft_printf("count moves = %d\n", data->count_moves);
	if (keycode == 53)
		ft_free_and_destroy(data);
	else if (keycode == 2 || keycode == 124)
	{
		data->count_plyer = 0;
		ft_right(data);
	}
	else if (keycode == 0 || keycode == 123)
	{
		data->count_plyer = 1;
		ft_left(data);
	}
	else if (keycode == 1 || keycode == 125)
		ft_down(data);
	else if (keycode == 13 || keycode == 126)
		ft_up(data);
	return (keycode);
}

void	ft_minilbx(t_mlx *data, t_node *witdh, int height)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_free(data);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, (witdh->data) * 50, (height - 1)
			* 50, "so_long");
	if (data->mlx_win == NULL)
		ft_free_and_destroy(data);
	ft_open_img(data);
	mlx_hook(data->mlx_win, 2, 0, ft_handl_input, data);
	mlx_hook(data->mlx_win, 17, 0, (void *)ft_free_and_destroy, data);
	mlx_loop_hook(data->mlx, &run, data);
	mlx_loop(data->mlx);
}
