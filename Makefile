# Standard
NAME                = push_swap

# Directories
LIBFT               = ./libft/libft.a
PRINTF              = ./ft_printf/libftprintf.a
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/

# Compiler and CFlags
CC                  = gcc
CFLAGS              = -Wall -Werror -Wextra
RM                  = rm -f

SRCS                = main.c \
					  commands_a.c \
					  commands_b.c \
					  commands_both.c \
					  cost_push.c \
					  error_checks.c \
					  find_min_max.c \
					  find_smallest_cost.c \
					  find_targets.c \
					  ft_check_sorted.c \
					  ft_find_last.c \
					  get_args.c \
					  init_nodes_a.c \
					  init_nodes_b.c \
					  prep_to_push.c \
					  pupulate.c \
					  push_swap_utils.c \
					  set_to_top.c \
					  sort_stack.c \
					  sort_three.c\
					  ft_atol.c\

SRC                 = $(addprefix $(SRC_DIR), $(SRCS))
OBJ                 = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all:                $(NAME)

$(LIBFT):
					@echo "Compiling libft..."
					@make -C ./libft > /dev/null
					@echo "\033[1;32mLibft.a has been created.\033[0m"
$(PRINTF):
					@echo "Compiling printf..."
					@make -C ./ft_printf > /dev/null
					@echo "\033[1;32mLibft.a has been created.\033[0m"

obj:
					@if [ -d $(OBJ_DIR) ]; then \
						echo "\033[1;31mDirectory already created.\033[0m"; \
					else \
						mkdir -p $(OBJ_DIR); \
						echo "Directory obj/ with files .o is being created..."; \
					fi

$(NAME):            $(LIBFT) $(PRINTF)  obj $(OBJ)
					@if [ -f $(NAME) ]; then \
						echo "\033[1;31mpush_swap still exists.\033[0m"; \
					else \
						echo "Compiling push_swap..."; \
						$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME); \
						echo "\033[1;32mDone.\033[0m"; \
					fi

# Compile object files from source files
$(OBJ_DIR)/%.o:     $(SRC_DIR)/%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
					@echo "\033[1;32mFile created.\033[0m";

clean:
					@echo "Removing obj/..."
					@$(RM) -r $(OBJ_DIR)
					@echo "Removing libft/obj..."
					@make clean -C ./libft > /dev/null
					@make clean -C ./ft_printf > /dev/null
					@echo "\033[1;32mAll Done for clean.\033[0m"

fclean:             clean
					@echo "Removing push_swap..."
					@$(RM) $(NAME)
					@echo "Removing libft.a..."
					@$(RM) $(LIBFT)
					@echo "Removing printf.a..."
					@$(RM) $(PRINTF)
					@echo "\033[1;32mDone.\033[0m"

re:                 fclean all

.PHONY:             all obj clean fclean re
