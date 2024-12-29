/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:00:01 by sbourziq          #+#    #+#             */
/*   Updated: 2024/03/12 22:00:03 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	char			**str;
	int				height;
	int				width;
	int				count;
	int				count_plyer;
	int				count_door;
	int				count_enemy;
	int				speed;
	int				x;
	int				i;
	int				j;
	int				count_enemy_left;
	int				count_moves;
}					t_mlx;

typedef struct s_img
{
	void			*img_wall;
	void			*path_wall;
	void			*path_wall2;
	void			*img_wall2;
	void			*path_wall3;
	void			*img_wall3;
	int				img_height;
	int				img_witdh;
	void			*img_player;
	void			*path_player;
	int				n;
	int				j;
	void			*img_gold1;
	void			*path_gold1;
	void			*img_door;
	void			*path_door;
	void			*img_door_open;
	void			*path_enemy;
	void			*img_enemy;

}					t_img;

typedef struct s_cout
{
	int				check_p;
	int				check_e;
	int				check_n;
	int				check_c;

}					t_count;

ssize_t				ft_strlen(char *s);
char				*ft_substr(char *s, int start, int end);
char				*ft_strjoin(char *s1, char *s2);
char				*get_next_line(int fd);
int					ft_checkline(char *str);
char				*ft_readfile(int fd);
t_node				*ft_node(int numbr, t_node *result);
t_node				*ft_lstnew(int content);
void				ft_sam_number(t_node *number);
int					ft_check_char(char *str, char c);
int					check_number(char *res);
void				ft_count_line(int *height, t_node **witdh, char **argv);
void				ft_str_map(char **str, char **argv);
void				ft_open_img(t_mlx *data);
void				ft_right(t_mlx *data);
void				ft_down(t_mlx *data);
void				ft_up(t_mlx *data);
void				ft_left(t_mlx *data);
void				ft_free(t_mlx *data);
int					ft_check_exit(char **map, t_mlx *data);
char				**ft_flod_fill(int x, int y, char **str, t_mlx *data);
int					ft_check_map(char **str, t_mlx *data);
int					ft_check_exit1(char **map, t_mlx *data);
int					ft_check_c(t_mlx *data);
void				ft_free_and_destroy(t_mlx *data);
void				ft_path_map(char **argv);
int					ft_strlen1(char *str);
int					ft_strcmp(char *cmp);
void				ft_fire_frames(t_img *img, t_mlx *data);
void				ft_put_frames(t_img *img, t_mlx *data);
int					ft_check_map2(char **str, t_mlx *data);
void				ft_check_enemy_down(t_mlx *data, int i, int j);
void				ft_check_enemy_up(t_mlx *data, int i, int j);
void				ft_check_enemy_left(t_mlx *data, int i, int j);
void				ft_check_enemy_right(t_mlx *data, int i, int j);
void				ft_print(t_mlx *data);
void				ft_print_lost(t_mlx *data);
void				ft_enemy(t_img *img, t_mlx *data);
int					ft_printf(const char *str, ...);
void				ft_putchar(char ptr, int *len);
void				ft_putstr(char *str, int *len);
void				ft_hexadecimal(unsigned long int decimal, int *len);
void				ft_putnbr(int n, int *len);
void				ft_putnbrunsigned(unsigned int n, int *len);
void				ft_print_hex(unsigned int low, char str, int *len);
void				ft_speed_right(t_mlx *data, int i, int j);
void				ft_speed_left(t_mlx *data, int i, int j);
void				ft_move_enemy(t_mlx *data, int i, int j, int x);
void				ft_check_first_wall(char **res, int height);
void				ft_check_last_wall(char **res);
void				ft_enemy_speed(t_mlx *data, int i, int j, int x);
void				loaction_enemy(t_mlx *data);
int					run(t_mlx *data);
int					ft_handl_input(int keycode, t_mlx *data);
void				ft_minilbx(t_mlx *data, t_node *witdh, int height);
void				ft_count_char(char *res, t_count *check);
int					ft_check_map3(char **str, t_mlx *data);

#endif