SRC = so_long.c get_next_line.c get_next_line_utils.c node.c ft_handl_error.c\
ft_str_map.c ft_moves.c ft_free.c ft_use_flod_fill.c ft_check_c.c ft_correct_map.c\
ft_frames.c ft_use_flod_fill2.c ft_enemy.c ft_print_hex.c ft_printf.c ft_putchar.c\
ft_puthexadecimal.c ft_putnbr.c ft_putnbrunsigned.c ft_putstr.c ft_enemy_moves.c\
ft_handl_error_map.c ft_minilbx.c ft_flod_fill3.c
OBJS= ${SRC:.c=.o}
NAME= so_long
RM = rm -f
CC = cc
CFLAGC = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $(CFLAGC) -lmlx -framework OpenGL -framework AppKit $^ -o $@ 
gcc main.o -o main -fsanitize=address -static-libasan

%.o : %.c
	$(CC) $(CFLAGC) -Imlx -c $<

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re: fclean all

.PHONY : all fclean clean re

