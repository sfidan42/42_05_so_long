SRCS		=	$(shell ls -t utils/*.c)
BSRCS		=	$(shell ls -t utils_bonus/*.c)
OBJS		=	$(SRCS:.c=.o)
BOBJS		=	$(BSRCS:.c=.o)
NAME 		=	so_long.a
BNAME 		=	so_long_bonus.a
NAME2		=	include/ft_printf/libftprintf.a
NAME3		=	include/libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-lbsd -lmlx -lXext -lX11

all: $(NAME2) $(NAME3) $(NAME) so_long

bonus: $(NAME2) $(NAME3) $(BNAME) so_long_bonus

$(NAME): $(SRCS)
	make -C utils
	ar rcs $(NAME) $(OBJS)

$(BNAME): $(BSRCS)
	make -C utils_bonus
	ar rcs $(BNAME) $(BOBJS)

$(NAME2):
	@make -C include/ft_printf

$(NAME3):
	@make -C include/libft

so_long: so_long.c
	@gcc $(CFLAGS) so_long.c $(NAME) $(NAME2) $(NAME3) $(MLX_FLAGS) -o so_long

so_long_bonus: so_long_bonus.c
	@gcc $(CFLAGS) so_long_bonus.c $(BNAME) $(NAME2) $(NAME3) $(MLX_FLAGS) -o so_long_bonus

clean:
	make -C utils clean
	make -C utils_bonus clean
	@make -C include/ft_printf clean
	@make -C include/libft clean

fclean: clean
	rm -f $(NAME) $(BNAME) $(NAME2) $(NAME3) so_long so_long_bonus

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
