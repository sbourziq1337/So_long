/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frames.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:55:20 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:55:25 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fire_frames(t_img *img, t_mlx *data)
{
	if (data->count <= 10)
		img->path_gold1 = "all_img/fire1.xpm";
	else if (data->count > 10 && data->count <= 10 * 2)
		img->path_gold1 = "all_img/fire2.xpm";
	else if (data->count > 10 * 2 && data->count <= 10 * 3)
		img->path_gold1 = "all_img/fire3.xpm";
	else if (data->count > 10 * 3 && data->count <= 10 * 4)
		img->path_gold1 = "all_img/fire4.xpm";
	else if (data->count > 10 * 4 && data->count <= 10 * 5)
		img->path_gold1 = "all_img/fire5.xpm";
	else if (data->count > 10 * 5 && data->count <= 10 * 6)
		img->path_gold1 = "all_img/fire6.xpm";
	else if (data->count > 10 * 6 && data->count <= 10 * 7)
		img->path_gold1 = "all_img/fire7.xpm";
}

void	ft_put_frames(t_img *img, t_mlx *data)
{
	if (data->count_door == 0)
		img->path_door = "all_img/door1.xpm";
	else if (data->count_door > 0 && data->count_door <= 15)
		img->path_door = "all_img/door3.xpm";
	else if (data->count_door > 15 && data->count_door <= 15 * 2)
		img->path_door = "all_img/door3.xpm";
	else if (data->count_door > 15 * 2 && data->count_door <= 15 * 3)
		img->path_door = "all_img/door4.xpm";
	else if (data->count_door > 15 * 3)
		img->path_door = "all_img/door5.xpm";
	if (data->count_plyer == 1)
		img->path_player = "all_img/player_left.xpm";
	else if (data->count_plyer == 0)
		img->path_player = "all_img/palyer_game.xpm";
}

void	ft_enemy_left(t_img *img, t_mlx *data)
{
	if (data->count_enemy_left == -1)
		img->path_enemy = "all_img/enemy_left.xpm";
	else if (data->count_enemy_left == -2)
		img->path_enemy = "all_img/enemy_left1.xpm";
	else if (data->count_enemy_left == -3)
		img->path_enemy = "all_img/enemy_left2.xpm";
	else if (data->count_enemy_left == -4)
		img->path_enemy = "all_img/enemy_left3.xpm";
	else if (data->count_enemy_left == -5)
		img->path_enemy = "all_img/enemy_left4.xpm";
	else if (data->count_enemy_left == -6)
		img->path_enemy = "all_img/enemy_left5.xpm";
}

void	ft_enemy(t_img *img, t_mlx *data)
{
	if (data->count_enemy_left >= 0)
	{
		if (data->count_enemy_left == 0)
			img->path_enemy = "all_img/enemy.xpm";
		else if (data->count_enemy_left == 1)
			img->path_enemy = "all_img/enemy2.xpm";
		else if (data->count_enemy_left == 2)
			img->path_enemy = "all_img/enemy3.xpm";
		else if (data->count_enemy_left == 3)
			img->path_enemy = "all_img/enemy4.xpm";
		else if (data->count_enemy_left == 4)
			img->path_enemy = "all_img/enemy5.xpm";
		else if (data->count_enemy_left == 5)
			img->path_enemy = "all_img/enemy6.xpm";
	}
	else if (data->count_enemy_left < 0)
		ft_enemy_left(img, data);
}
