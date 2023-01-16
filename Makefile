SRCS		=	$(shell ls utils/*)
BSRCS		=	$(shell ls bonus_utils/*)
OBJS		=	$(SRCS:.c=.o)
BOBJS		=	$(BSRCS:.c=.o)
NAME 		=	so_long.a
NAME2		=	include/ft_printf/libftprintf.a
NAME3		=	include/libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lbsd -lmlx -lXext -lX11

all: $(NAME2) $(NAME3) $(NAME) so_long

$(NAME): $(SRCS)
	make -C utils
	ar rcs $(NAME) $(OBJS)

$(NAME2):
	make -C include/ft_printf

$(NAME3):
	make -C include/libft

so_long: so_long.c
	gcc $(CFLAGS) so_long.c $(NAME) $(NAME2) $(NAME3) $(MLX_FLAGS) -o so_long

clean:
	make -C utils clean
	make -C bonus_utils clean
	make -C include/ft_printf clean
	make -C include/libft clean

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME3) so_long

re: fclean all

bonus_archive: $(NAME2) $(NAME3) $(NAME)
	make -C bonus_utils
	ar rcs $(NAME) $(BOBJS)

bonus: bonus_archive so_long

.PHONY: all compile clean fclean re bonus bonus_archive
