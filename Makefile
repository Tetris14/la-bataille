##
## TRISTAN GORY PROJECT, 2022
## la bataille makefile
## File description:
## Makefile
##

NAME	=	labataille

SRC		=	$(wildcard sources/*.cpp)

OBJ		=	$(SRC:.cpp=.o)

OBJ_TEST	=	$(SRC:.cpp=.gcno) $(SRC:.cpp=.gcda)

CXXFLAGS	=	-I includes -W -Wall -pthread

CXX	=	g++

RM	=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) -g3

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	$(RM) ../../../lib/$(NAME)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY:	all clean fclean re debug