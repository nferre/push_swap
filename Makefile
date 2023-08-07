NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = push_swap.c \
	  push_swap_utils.c \
	  push_swap_more_utils.c \
	  rules.c \
	  verify.c \
	  sort.c \
	  split.c \
	  more_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(OBJ) $(FLAGS) -o push_swap	

%.o: %.c
	gcc $(FLAGS) -c $^ -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
