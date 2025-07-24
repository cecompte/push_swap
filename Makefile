CC				= cc
CFLAGS			= -g3 -Wall -Wextra -Werror -MMD -MP
INCLUDES		= -Ilibft -Iincludes
NAME			= push_swap
BONUS_NAME		= checker

# Sources
SRC_PATH		= src/
SRC				= main.c \
					initialize_stack/initialize_stack.c \
					initialize_stack/utils.c \
					initialize_stack/clear_exit.c \
					operations/push.c \
					operations/swap.c \
					operations/rotate.c \
					operations/rev_rotate.c \
					algo/algo_utils.c \
					algo/count_operations.c \
					algo/find_targets.c \
					algo/simple_algo.c \
					algo/turk_algo.c
BONUS			= bonus/checker_bonus.c \
					bonus/get_next_line/get_next_line_utils.c \
					bonus/get_next_line/get_next_line.c \
					bonus/init_stack_bonus/init_stack_bonus.c \
					bonus/init_stack_bonus/utils_bonus.c \
					bonus/init_stack_bonus/clear_exit_bonus.c \
					bonus/operations_bonus/ops_bonus.c \
					bonus/operations_bonus/double_bonus.c
SOURCES			= $(addprefix $(SRC_PATH), $(SRC))
BONUS_SOURCES	= $(addprefix $(SRC_PATH), $(BONUS))

# Objects
OBJ_PATH		= obj/
OBJ				= $(SRC:.c=.o)
BONUS_OBJ		= $(BONUS:.c=.o)
OBJECTS			= $(addprefix $(OBJ_PATH), $(OBJ))
BONUS_OBJECTS	= $(addprefix $(OBJ_PATH), $(BONUS_OBJ))
DEP				= $(SRC:.c=.d)
BONUS_DEP		= $(BONUS:.c=.d)
DEPS			= $(addprefix $(OBJ_PATH), $(DEP))
BONUS_DEPS		= $(addprefix $(OBJ_PATH), $(BONUS_DEP))

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

bonus: $(LIBFT) $(BONUS_NAME)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building $(NAME)...$(RESET)\n" $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_FLAGS) -o $(NAME)
	@printf "$(BLUE)%s$(RESET): $(GREEN)Successfully built $(NAME)$(RESET)\n" $(NAME)

$(BONUS_NAME) : $(BONUS_OBJECTS)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building $(BONUS_NAME)...$(RESET)\n" $(BONUS_NAME)
		@$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT_FLAGS) -o $(BONUS_NAME)
		@printf "$(BLUE)%s$(RESET): $(GREEN)Successfully built $(BONUS_NAME)$(RESET)\n" $(BONUS_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)initialize_stack
	@mkdir $(OBJ_PATH)operations
	@mkdir $(OBJ_PATH)algo
	@mkdir $(OBJ_PATH)bonus
	@mkdir $(OBJ_PATH)bonus/get_next_line
	@mkdir $(OBJ_PATH)bonus/init_stack_bonus
	@mkdir $(OBJ_PATH)bonus/operations_bonus

$(LIBFT):
	@make -C $(LIBFT_DIR) all --no-print-directory

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Cleaning object files...$(RESET)\n"
	@rm -rf obj
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Full clean...$(RESET)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean all

bonus: all

-include $(DEPS)

.PHONY: all clean fclean re bonus
.DELETE_ON_ERROR:
