NAME : push_swap.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = xxx.c

OBJ = $(SRC :.c=.o)

AR = -ar -rc

all = $(NAME)

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ)
%.o: %.c

$(CC) $(CFLAGS) -c $< -o $@

clean : rm -f $(OBJ)

fclean : rm -f $(NAME)

re ; fclean all

.PHONY: all fclean clean re% 
