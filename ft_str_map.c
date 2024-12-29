/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:57:31 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:58:01 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_img *img, t_mlx *data)
{
	if (img->img_wall == NULL || img->img_wall2 == NULL
		|| img->img_wall3 == NULL || img->img_player == NULL
		|| img->img_gold1 == NULL || img->img_door == NULL)
	{
		ft_printf("\nYou have a problem with your image paths.\n");
		ft_free_and_destroy(data);
	}
}

void	ft_str_map(char **str, char **argv)
{
	char	*res;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("this map does not exit\n");
		exit(0);
	}
	res = get_next_line(fd);
	while (res != NULL)
	{
		str[count++] = res;
		res = get_next_line(fd);
	}
	str[count] = NULL;
	free(res);
}

void	ft_put_img(t_img *img, t_mlx *data, int x, int y)
{
	char	move_counter[30];

	sprintf(move_counter, "COUNT MOVEMENT %d", data->count_moves);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_wall2, y * 50, x
		* 50);
	mlx_string_put(data->mlx, data->mlx_win, (data->width), (data->height - 1),
		0x0000FF, move_counter);
	if (data->str[x][y] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_player, y
			* 50, x * 50);
	else if (data->str[x][y] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_gold1, y
			* 50, x * 50);
	else if (data->str[x][y] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_door, y * 50,
			x * 50);
	else if (data->str[x][y] == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_win, img->img_enemy, y
			* 50, x * 50);
}

void	ft_creat_img(t_img *img, t_mlx *data)
{
	img->n = 0;
	ft_enemy(img, data);
	ft_fire_frames(img, data);
	ft_put_frames(img, data);
	img->path_wall = "all_img/new_wall.xpm";
	img->path_wall2 = "all_img/testwall.xpm";
	img->path_wall3 = "all_img/wall2.xpm";
	img->img_wall = mlx_xpm_file_to_image(data->mlx, img->path_wall,
			&img->img_height, &img->img_witdh);
	img->img_wall2 = mlx_xpm_file_to_image(data->mlx, img->path_wall2,
			&img->img_height, &img->img_witdh);
	img->img_wall3 = mlx_xpm_file_to_image(data->mlx, img->path_wall3,
			&img->img_height, &img->img_witdh);
	img->img_player = mlx_xpm_file_to_image(data->mlx, img->path_player,
			&img->img_height, &img->img_witdh);
	img->img_gold1 = mlx_xpm_file_to_image(data->mlx, img->path_gold1,
			&img->img_height, &img->img_witdh);
	img->img_door = mlx_xpm_file_to_image(data->mlx, img->path_door,
			&img->img_height, &img->img_witdh);
	img->img_enemy = mlx_xpm_file_to_image(data->mlx, img->path_enemy,
			&img->img_height, &img->img_witdh);
	check_images(img, data);
}

void	ft_open_img(t_mlx *data)
{
	t_img	img;

	ft_creat_img(&img, data);
	while (img.n < data->height - 1)
	{
		img.j = 0;
		while (img.j < data->width)
		{
			if ((data->str[img.n][img.j] == '1') && (img.n != 0 && img.j != 0))
				mlx_put_image_to_window(data->mlx, data->mlx_win, img.img_wall,
					img.j * 50, img.n * 50);
			if ((data->str[img.n][img.j] == '1') && (img.n == data->height - 2
					|| img.j == (data->width - 1)))
				mlx_put_image_to_window(data->mlx, data->mlx_win, img.img_wall3,
					img.j * 50, img.n * 50);
			if ((data->str[img.n][img.j] == '1') && ((img.n == 0
						|| img.j == 0)))
				mlx_put_image_to_window(data->mlx, data->mlx_win, img.img_wall3,
					img.j * 50, img.n * 50);
			else if (data->str[img.n][img.j] != '1')
				ft_put_img(&img, data, img.n, img.j);
			img.j++;
		}
		img.n++;
	}
}
