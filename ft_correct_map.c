/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:28 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 21:54:33 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13) && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *cmp)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ".ber";
	while (cmp[i] != ' ' && !(cmp[i] >= 9 && cmp[i] <= 13) && cmp[i] != '\0')
	{
		if (cmp[i] != ptr[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_path_map(char **argv)
{
	int	fd;

	if (ft_strcmp(argv[1] + (ft_strlen1(argv[1]) - 4)) == 1)
	{
		ft_printf("your map name is not correct\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("this map does not exist\n");
		exit(1);
	}
}
