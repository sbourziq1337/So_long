/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:59:15 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:59:26 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_mlx *data)
{
	ft_printf("your map is not correct\n");
	ft_free(data);
	exit(1);
}

int	run(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	(data->speed)++;
	if (data->speed == 15)
	{
		data->speed = 0;
		loaction_enemy(data);
		ft_enemy_speed(data, data->i, data->j, data->x);
	}
	data->x = 0;
	data->i = 0;
	data->j = 0;
	(data->count)++;
	if (data->count == 10 * 7)
		data->count = 0;
	if (ft_check_c(data) == 1)
		(data->count_door)++;
	ft_open_img(data);
	return (1);
}

void	ft_all_var(int *i, int *height, t_mlx *data)
{
	*height = 1;
	*i = 1;
	data->count = 0;
	data->count_door = 0;
	data->count_plyer = 0;
	data->count_enemy = 0;
	data->x = 0;
	data->i = 0;
	data->j = 0;
	data->speed = 0;
	data->count_enemy_left = 0;
}

void	ft_handl_map(int *height, t_mlx *data, char **argv, t_node **witdh)
{
	ft_path_map(argv);
	ft_count_line(height, witdh, argv);
	ft_sam_number(*witdh);
	data->str = (char **)malloc(*height * sizeof(char *) + 1);
	if (data->str == NULL)
		return ;
	data->height = *height;
	data->width = (*witdh)->data;
	ft_str_map(data->str, argv);
	ft_check_last_wall(&data->str[(*height) - 2]);
	if (ft_check_map(data->str, data) == 1)
		ft_print_map(data);
	ft_free(data);
	ft_str_map(data->str, argv);
	if (ft_check_map2(data->str, data) == 1)
		ft_print_map(data);
	ft_free(data);
	ft_str_map(data->str, argv);
	if (ft_check_map3(data->str, data) == 1)
		ft_print_map(data);
	ft_free(data);
	ft_str_map(data->str, argv);
}

int	main(int argc, char **argv)
{
	int		height;
	int		i;
	t_node	*witdh;
	t_mlx	data;

	ft_all_var(&i, &height, &data);
	if (argc == 1)
	{
		ft_printf("we need map\n");
		return (0);
	}
	else if (argc == 2)
	{
		ft_handl_map(&height, &data, argv, &witdh);
		ft_minilbx(&data, witdh, height);
		system("leaks a.out");
	}
	else
		ft_printf("you have a lot of argimont\n");
	return (0);
}
