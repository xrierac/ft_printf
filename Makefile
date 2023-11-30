NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .
LIBFT_DIR = libft/

SRCS := ft_printf.c ft_utoa.c ft_dec_to_hex.c ft_dec_to_xhex.c ft_printf_utils.c
LIBFT := $(LIBFT_DIR)/libft.a

OBJS := $(SRCS:.c=.o)

$(NAME) : $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT) :
	make -C $(LIBFT_DIR)
	cp $(LIBFT) .
	mv libft.a $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@ 

all: $(NAME)	

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean 
	rm -f $(LIBFT)
	rm -f $(NAME)
	

re: fclean all

.PHONY : all clean fclean re libft
