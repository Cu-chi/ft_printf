CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD
NAME = libftprintf.a
INCLUDES = includes
LIBFT = libft/libft.a

SRC_DIR = srcs
SRC_FIL = ft_printf.c \
	ft_printf_flags.c \
	ft_printf_write.c \
	ft_printf_write_u.c \
	ft_itoa_u.c \
	ft_putnbr_hex.c \
	ft_useful.c \
	ft_printf_hex.c \
	ft_printf_list.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FIL))
OBJS = $(SRCS:.c=.o)
DEP = $(OBJS:.o=.d)

-include $(DEP)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	ar -rcs $@ $(OBJS)

bonus: all

%.o: %.c 
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean: libft_clean
	rm -f $(OBJS)
	rm -f $(DEP)

fclean: libft_fclean clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C libft/ all bonus

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

.PHONY: all clean fclean re bonus libft_fclean libft_clean
