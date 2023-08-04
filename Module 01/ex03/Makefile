NAME	= violence
RM		= rm -f
CXX		= c++
CXXFLAGS	= -std=c++98 -Wall -Werror -Wextra

SRC		= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJDIR = ./objects/
OBJFILES = $(SRC:.cpp=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEPT = Weapon.hpp HumanA.hpp HumanB.hpp

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