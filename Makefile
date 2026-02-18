
NAME			=	push_swap

LIBFT			=	./libft/libft.a
HEAD			=	head/
SRC_DIR			=	src/
OBJ_DIR			=	obj/

cc				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -I head/
RM				=	rm -rf

OPERATION_DIR	=	$(SRC_DIR)operations/push.c \
					$(SRC_DIR)operations/revr.c \
					$(SRC_DIR)operations/rotate.c \
					$(SRC_DIR)operations/sort_stack.c \
					$(SRC_DIR)operations/sort_three.c \
					$(SRC_DIR)operations/swap.c

PUSH_UTILS_DIR	=	$(SRC_DIR)push_utils/error_handling.c \
					$(SRC_DIR)push_utils/init_a_to_b.c \
					$(SRC_DIR)push_utils/init_b_to_a.c \
					$(SRC_DIR)push_utils/push_swap.c \
					$(SRC_DIR)push_utils/split.c \
					$(SRC_DIR)push_utils/init_stack.c \
					$(SRC_DIR)push_utils/stack_utils.c \
					$(SRC_DIR)push_utils/cost_calculate.c 

SRCS			=	$(OPERATION_DIR) $(PUSH_UTILS_DIR)

OBJ				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
		@make all

$(LIBFT):
		@make -C ./libft

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
					@echo "linking $(NAME)..."
					@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -rf $(OBJ_DIR)
					@make clean -C ./libft

fclean:		clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re:			fclean all

.PHONY:		start all clean fclean re
