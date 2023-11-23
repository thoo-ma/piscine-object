CXXFLAGS = -Wall -Wextra -Wconversion -std=c++98

SRC = Tools.cpp Worker.cpp Workshop.cpp main.cpp

OBJ = $(addsuffix .o, $(basename $(SRC)))

NAME = a.out

# CXX = clang++

all: $(NAME)

$(NAME): $(OBJ) ; $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean: ; $(RM) $(OBJ)

fclean: clean ; $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re