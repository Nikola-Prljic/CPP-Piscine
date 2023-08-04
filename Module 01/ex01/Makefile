NAME	= zombie
CXX		= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

SRC		= main.cpp Zombie.cpp zombieHorde.cpp
OBJDIR = ./objects/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEPT = Zombie.hpp

.PHONY: clean fclean all val

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEPT)
	$(CXX) $(CXXFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all