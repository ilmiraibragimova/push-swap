NAME1 = push_swap
NAME2 = checker
FLAGS = -Wall -Wextra -Werror 
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
INC = $(addprefix $(INC_DIR),ft_push_swap.h)

SRC_FILESP = ft_push_swap.c ft_arg.c ft_clear.c ft_do.c ft_do_instrution.c \
	ft_fivehundred.c ft_hundred.c ft_rules.c ft_sort3.c ft_two.c \
	ft_util.c ft_valid.c
SRC_FILESCH = cheker.c ft_arg.c ft_clear.c ft_do.c ft_do_instrution.c \
	ft_rules.c ft_util.c ft_valid.c

OBJ_FILESP = $(SRC_FILESP:.c=.o)
OBJ_FILESCH = $(SRC_FILESCH:.c=.o)

SRCP = $(addprefix $(SRC_DIR), $(SRC_FILESP))
SRCCH = $(addprefix $(SRC_DIR), $(SRC_FILESCH))
OBJP = $(addprefix $(OBJ_DIR), $(OBJ_FILESP))
OBJCH = $(addprefix $(OBJ_DIR), $(OBJ_FILESCH))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LNK  = -L $(LIBFT_DIR) -lft

all: obj $(LIBFT) $(NAME1) $(NAME2)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(INC) $(LIBFT_DIR)
	gcc $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME1): $(OBJP)
	gcc $(OBJP) $(LNK)  -o $(NAME1)
$(NAME2): $(OBJCH)
	gcc $(OBJCH) $(LNK)  -o $(NAME2)
clean:
	rm -Rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: all clean fclean re
