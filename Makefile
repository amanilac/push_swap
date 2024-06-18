NAME = push_swap
DEBUG_NAME = debug.out

STANDARD_CC = cc
STANDARD_FLAGS = -Wall -Wextra -Werror
DEBUG_CC = cc
DEBUG_FLAGS = -g -fsanitize=address,undefined,integer

SRC_DIR = src/
OBJ_DIR = objs/

SRC_NAMES = actions.c \
			free.c \
			index.c \
			main.c \
			parsing.c \
			push.c \
			radix.c \
			rev_rotate.c \
			rotate.c \
			sort_utils.c \
			sort.c \
			stack_comms.c \
			swap.c \

LIBFT = libft/libft.a

HEADER_NAMES = push_swap.h

################################################################################

CC = $(STANDARD_CC)
CFLAGS = $(STANDARD_FLAGS)

SRCS = $(addprefix $(SRC_DIR)$(SRC_PATH_MANDATORY), $(SRC_NAMES))
SRCS_BONUS = $(addprefix $(SRC_DIR)$(SRC_PATH_BONUS), $(SRC_BONUS_NAMES))

OBJS = $(SRC_NAMES:%.c=$(OBJ_DIR)$(SRC_PATH_MANDATORY)%.o)
OBJS_BONUS = $(SRC_BONUS_NAMES:%.c=$(OBJ_DIR)$(SRC_PATH_BONUS)%.o)

OBJS_DEBUG = $(SRC_NAMES:%.c=$(OBJ_DIR)debug/$(SRC_PATH_MANDATORY)%.o)
OBJS_DEBUG_BONUS = $(SRC_BONUS_NAMES:%.c=$(OBJ_DIR)debug/$(SRC_PATH_BONUS)%.o)

HEADERS = $(addprefix $(SRC_DIR)$(SRC_PATH_MANDATORY), $(HEADER_NAMES))
HEADERS_BONUS = $(addprefix $(SRC_DIR)$(SRC_PATH_BONUS), $(HEADER_BONUS_NAMES))

.PHONY: all bonus debug_set debug debug_bonus \
.clean clean fclean re

$(OBJ_DIR)%.o \
$(OBJ_DIR)debug/%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)$< $(PURPLE)$(CFLAGS) $(RED)> $(GREY)$@$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################################

all: makelibft $(NAME)

makelibft:
	@cd libft && make

$(NAME): $(OBJS)
	@cc $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

.bonus: $(NAME) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)
	@touch .bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

bonus: .bonus

################################################################################

$(DEBUG_NAME): $(OBJS_DEBUG)
	@ar rcs $(NAME) $^
	@$(CC) $(CFLAGS) $(NAME) -o $(DEBUG_NAME)
	@touch .debug
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Mandatory part done$(DEFAULT)"

debug_set:
	$(eval CC = $(DEBUG_CC))
	$(eval CFLAGS = $(DEBUG_FLAGS))

.debug: debug_set $(DEBUG_NAME)

debug: .debug

.debug_bonus: debug_set $(NAME) $(OBJS_DEBUG_BONUS)
	@$(CC) $(CFLAGS) $(NAME) -o $(DEBUG_NAME)
	@touch .debug_bonus
	@echo "$(GREY)$(SOFT_NAME) $(DEBUG_NAME) $(DEFAULT)| $(GREEN)Bonus part done$(DEFAULT)"

debug_bonus: .debug_bonus

################################################################################

.clean:
	@make clean -C ./libft
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(OBJ_DIR), .bonus, .debug, and .debug_bonus"
	@rm -rf $(OBJ_DIR) .bonus .debug .debug_bonus

clean: .clean

fclean: .clean
	@echo "$(GREY)$(SOFT_NAME) $(DEFAULT)| $(RED)Removing $(DEFAULT)$(NAME) and $(DEBUG_NAME)"
	@rm -rf $(NAME) $(DEBUG_NAME)

re: fclean all

################################################################################

GREEN = \033[38;5;84m
RED = \033[38;5;9m
BLUE = \033[38;5;45m
#PURPLE = \033[38;5;63m
PINK = \033[38;5;207m
PURPLE = \033[38;5;165m
BLACK = \033[38;5;0m
BG_WHITE = \033[48;5;15m
BG_GREEN = \033[48;5;84m
BG_RED = \033[48;5;9m
BG_PURPLE = \033[48;5;54m
GREY = \033[38;5;8m
BOLD = \033[1m
DEFAULT = \033[0m
CHECKMARK = \xE2\x9C\x93