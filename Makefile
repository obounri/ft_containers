include .env

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =iterators.hpp \
		vector.hpp \
		stack.hpp \
		fcts.hpp \
		map.hpp \
		pair.hpp \
		Tree.hpp \
		Type_traits.hpp

NAME = containers
SRC_FILE =  main.cpp
# OBJ_FILE = $(SRC_FILE:.cpp=.o)

all : $(NAME)

push:
	git add -A
	git commit -m "$(msg)"
	git push -u https://obounri:$(GIT_KEY)@github.com/obounri/ft_containers.git master 

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