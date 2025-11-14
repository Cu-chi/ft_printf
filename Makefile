CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCLUDES = includes/ft_printf.h
LIBFT = libft/libft.a

SRC_DIR = srcs
SRC_FIL = ft_printf.c \
	ft_printf_flags.c \
	ft_printf_write.c \
	ft_itoa_u.c \
	ft_putnbr_hex.c \
	ft_printf_list.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FIL))

#BONUS_FIL = ft_bonus.c ft_bonus2.c

OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(BONUS_FIL:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(INCLUDES)
	cp $(LIBFT) $@
	ar -rcs $@ $(OBJS)

#bonus: $(NAME) $(BONUS_OBJS)
#	ar -rcs $(NAME) $(BONUS_OBJS)

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $^ -o $@

clean: libft_clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

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
