/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handl_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:56:05 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:56:09 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(char **res, int count)
{
	if ((*res)[0] != '1')
	{
		free(*res);
		ft_printf("Error in your map (first wall)\n");
		exit(1);
	}
	if ((*res)[count + 1] == '\n')
	{
		if ((*res)[count] != '1')
		{
			free(*res);
			ft_printf("Error in your map (last wall)\n");
			exit(1);
		}
	}
}

void	ft_check_first_wall(char **res, int height)
{
	if ((height) == 1)
	{
		if (check_number(*res) == 1)
		{
			free(*res);
			ft_printf("Error in your map (first wall)\n");
			exit(1);
		}
	}
}

void	ft_variable(int *fd, char **argv, int *count, t_count *check)
{
	*fd = open(argv[1], O_RDONLY);
	if (*fd == -1)
	{
		ft_printf("this map does not exit\n");
		exit(0);
	}
	*count = 0;
	check->check_e = 0;
	check->check_p = 0;
	check->check_n = 0;
}

void	ft_morre_line(char **res, t_count *check)
{
	free(*res);
	if (check->check_e != 1 || check->check_p != 1 || check->check_n > 1
		|| check->check_c < 1)
	{
		ft_printf("error , in your characters\n");
		exit(1);
	}
}

void	ft_count_line(int *height, t_node **witdh, char **argv)
{
	char	*res;
	int		fd;
	int		count;
	t_count	check;

	ft_variable(&fd, argv, &count, &check);
	res = get_next_line(fd);
	while (res != NULL)
	{
		ft_count_char(res, &check);
		while (res[count] != '\n' && res[count] != '\0')
		{
			ft_check_wall(&res, count);
			count++;
		}
		*witdh = ft_node(count, *witdh);
		ft_check_first_wall(&res, *height);
		(*height)++;
		count = 0;
		free(res);
		res = get_next_line(fd);
	}
	ft_morre_line(&res, &check);
}
