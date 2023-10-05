NAME	= ex01
RM		= rm -f
CXX		= c++
CXXFLAGS= -std=c++98 -Wall -Werror -Wextra
SRC		= main.cpp
OBJDIR	= ./objects/
OBJFILES = $(SRC:.cpp=.o)
OBJ		= $(addprefix $(OBJDIR), $(OBJFILES))

DEPT = iter.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: ./%.cpp $(DEPT)
	$(CXX) $(CXXFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
			@rm -rf $(OBJDIR)
			@echo // objekt files removed //

fclean:		clean
			@$(RM) $(NAME)
			@echo // all files removed //

re:			fclean all
			@echo // Clenad and rebuild everything! //
