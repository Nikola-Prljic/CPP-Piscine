NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp RPN.cpp

OBJDIR = ./objects/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEPT = RPN.hpp

.PHONY: clean fclean all val

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEPT)
	$(CXX) $(CXXFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

val: all
	valgrind --track-origins=yes ./RPN "1 2 3"

clean:
	@rm -rf $(OBJDIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all