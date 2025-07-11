CC				= cc
CFLAGS			= -g3 -Wall -Wextra -Werror -MMD -MP
INCLUDES		= -Ilibft -Iincludes
NAME			= push_swap

# Sources
SRC_PATH		= src/
SRC				= main.c \
					initialize_stack/initialize_stack.c \
					initialize_stack/lst_utils.c \
					initialize_stack/other_utils.c \
					operations/push.c \
					operations/swap.c \
					operations/rotate.c \
					operations/rev_rotate.c \
					algo/algo_utils.c \
					algo/count_operations.c \
					algo/find_targets.c \
					algo/simple_algo.c \
					algo/turk_algo.c
SOURCES			= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH		= obj/
OBJ				= $(SRC:.c=.o)
OBJECTS			= $(addprefix $(OBJ_PATH), $(OBJ))
DEP				= $(SRC:.c=.d)
DEPS			= $(addprefix $(OBJ_PATH), $(DEP))

# libft
LIBFT			= libft.a
LIBFT_FLAGS		= -Llibft -lft
LIBFT_DIR		= ./libft

# Colors for display
RED				= \e[31m
GREEN			= \e[32m
YELLOW			= \e[33m
BLUE			= \e[34m
MAGENTA			= \e[35m
CYAN			= \e[36m
RESET			= \e[m

all: $(LIBFT) $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building $(NAME)...$(RESET)\n" $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)
	@printf "$(BLUE)%s$(RESET): $(GREEN)Successfully built $(NAME)$(RESET)\n" $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)initialize_stack
	@mkdir $(OBJ_PATH)operations
	@mkdir $(OBJ_PATH)algo

$(LIBFT):
	@make -C $(LIBFT_DIR) all --no-print-directory

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Cleaning object files...$(RESET)\n" $(NAME)
	@rm -rf obj
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Full clean...$(RESET)\n" $(NAME)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: all

-include $(DEPS)

.PHONY: all clean fclean re bonus
.DELETE_ON_ERROR:
