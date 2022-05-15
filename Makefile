NAME = containers

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = iterator_traits.hpp \
		iterator.hpp \
		Vector.hpp

SRC_FILE =  main.cpp
OBJ_FILE = $(SRC_FILE:.cpp=.o)

all : $(NAME)

%.o:%.cpp
	@$(CC) $(CFLAGS)  -c $< -o $@

$(NAME) : $(OBJ_FILE) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ_FILE) -o $(NAME)
	@./containers
	@make clean

clean :
	@rm -f $(OBJ_FILE)

fclean : clean
	rm -f $(NAME)

re : fclean all