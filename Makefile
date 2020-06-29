NAME = scop
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS = -I ./include `pkg-config --cflags glfw3`
INC_PATH = include/
OBJ_PATH = obj
SRC_PATH = src
SRC_NAME = main.c \
	   err.c \
	   glad.c \
	   view.c \
	   init.c \
	   utils.c \
	   glLoader.c \
	   lst_util.c \
	   obj_parsing.c \
	   libm/vec3_self.c \
	   libm/mat4_self.c \
	   libm/vec3_algebra.c \
	   libm/mat4_algebra.c \
	   libm/mat4_arithmetics.c \
	   libm/vec3_arithmetics.c \
	   libm/angle_utils.c

OBJ_NAME = $(SRC_NAME:c=o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ifeq ($(shell uname -s), Darwin)
	LDLIBS		=	-L ./libft -lft `pkg-config --static --libs glfw3` -framework OpenGL -framework Appkit
else ifeq ($(shell uname -s), Linux)
	LDLIBS		=	-L ./libft -lft `pkg-config --static --libs glfw3` -lGL -lX11 -lpthread -lXrandr -lXi -ldl
endif


all: $(NAME)
	@printf "Scop ready. \033[32m✔\033[0m  		                  \n"

$(NAME): $(OBJ)
	@printf "Making necessary libs                                           \n"
	@make -C libft 2> /dev/null || true
	@printf "Libraries done \033[32m✔\033[0m \nLinking...                    \n"
	@$(CC) $^ -o $@ $(LDLIBS)
	@printf "OBJs linked. 🔗                                                  \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/libm 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "Following files have been removed:                              \n"
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH)/libm 2> /dev/null || true
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "_________________________________\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean 2> /dev/null || true
	@printf "All files have been cleaned. \033[32m✔\033[0m                   \n"

re: fclean all

run: all
	./scop "asd"

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h
