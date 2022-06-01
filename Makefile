CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =srcs/iterators.hpp \
		srcs/vector.hpp \
		srcs/stack.hpp \
		srcs/fcts.hpp \
		srcs/map.hpp \
		srcs/pair.hpp \
		srcs/Tree.hpp \
		srcs/Type_traits.hpp

NAME = containers
SRC_FILE =  main.cpp
# OBJ_FILE = $(SRC_FILE:.cpp=.o)

all : $(NAME)

# %.o:%.cpp
# 	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(SRC_FILE) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC_FILE) -o $(NAME)
	@./containers
	@make clean

clean :
	@rm -f $(NAME) $(D_NAME)

fclean : clean

re : fclean all