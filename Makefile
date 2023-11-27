NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .
BONUS_DIR = .
LIBFT_DIR = libft/

SRCS := ft_printf.c
BONUSSRCS := .
LIBFT := $(LIBFT_DIR)/libft.a

BONUSOBJS := $(BONUSSRCS:.c=.o)
OBJS := $(SRCS:.c=.o)

$(NAME) : $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)	

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS) $(BONUSOBJS) .bonus

fclean: clean 
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) lib
	

re: fclean all

bonus : all

.bonus: $(OBJS) $(BONUSOBJS)
	ar rcs $(NAME) $?
	touch .bonus

.PHONY : all clean fclean re bonus libft
