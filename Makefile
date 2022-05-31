include .env

CC = c++

# CFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = iterator_traits.hpp \
		iterator.hpp \
		Vector.hpp \
		Stack.hpp \
		fcts.hpp \
		map.hpp \
		pair.hpp \
		red_black.hpp

NAME = containers
SRC_FILE =  main.cpp
# OBJ_FILE = $(SRC_FILE:.cpp=.o)

D_NAME = dbug
D_SRC_FILE =  dbug.cpp
# D_OBJ_FILE = $(D_SRC_FILE:.cpp=.o)

all : $(NAME)

debug : $(D_NAME)

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

$(D_NAME) : $(D_SRC_FILE) $(HEADER)
	@$(CC) $(CFLAGS) $(D_SRC_FILE) -o $(D_NAME)
	@./dbug
	@make clean

clean :
	@rm -f $(NAME) $(D_NAME)

fclean : clean

re : fclean all