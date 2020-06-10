NAME = scop
CC = gcc
CFLAGS = -Wall -Wextra -Werror  
CPPFLAGS = -Iinclude `pkg-config --cflags glfw3`
LDLIBS = -lft `pkg-config --static --libs glfw3` -framework OpenGL -framework AppKit
LDFLAGS = -Llibft
INC_PATH = include/
OBJ_PATH = obj
SRC_PATH = src
SRC_NAME = main.c \
	   glad.c \
	   init.c \
	   err.c \

OBJ_NAME = $(SRC_NAME:c=o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)
	@printf "Scop ready. \033[32m✔\033[0m  		                  \n"

$(NAME): $(OBJ)
	@printf "Making necessary libs                                           \n"
	@make -C libft 2> /dev/null || true
	@printf "Libraries done \033[32m✔\033[0m \nLinking...                    \n"
	@$(CC) $(LDLIBS) $(LDFLAGS) $^ -o $@
	@printf "OBJs linked. 🔗                                                  \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "Following files have been removed:                              \n"
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "_________________________________\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean 2> /dev/null || true
	@printf "All files have been cleaned. \033[32m✔\033[0m                   \n"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h
