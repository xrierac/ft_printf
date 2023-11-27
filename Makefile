NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = .
OBJ_DIR = .
BONUS_DIR = .
LIBFT_DIR = libft/

SRCS := 
BONUSSRCS := 

BONUSOBJS := $(BONUSSRCS:.c=.o)
OBJS := $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)


clean:
	rm -f $(OBJS) $(BONUSOBJS) .bonus

fclean: clean 
	rm -f $(NAME)

re: fclean all

bonus : .bonus

.bonus: $(OBJS) $(BONUSOBJS)
	ar rcs $(NAME) $?
	touch .bonus

.PHONY : all clean fclean re bonus