/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:48:03 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:48:13 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_c(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->str[i])
	{
		j = 0;
		while (data->str[i][j])
		{
			if (data->str[i][j] == 'C')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_sam_number(t_node *width)
{
	int	check;

	check = 0;
	while (width->next != NULL)
	{
		if (width->data == width->next->data)
			width = width->next;
		else
		{
			ft_printf("error in your map(morre line)\n");
			exit(1);
		}
	}
}

int	ft_check_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == c)
			i++;
		if (str[j] != '1' && str[j] != '0' && str[j] != 'C' && str[j] != 'P'
			&& str[j] != 'E' && str[j] != 'N' && str[j] != '\n')
		{
			ft_printf("error, bad characters\n");
			free(str);
			exit(1);
		}
		j++;
	}
	return (i);
}

int	check_number(char *res)
{
	int	i;

	i = 0;
	while (res[i] != '\n' && res[i] != '\0')
	{
		if (res[i] != '1')
			return (1);
		i++;
	}
	return (0);
}
