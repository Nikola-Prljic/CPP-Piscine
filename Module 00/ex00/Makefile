NAME	= megaphone
RM		= rm -f
CFLAGS	= -std=c++98 -Wall -Werror -Wextra

SRC		= main.cpp
OBJ		= $(SRC:.cpp=.o)
C++		= c++

all:		$(NAME)

$(NAME):	$(OBJ)
			$(C++) $(CFLAGS)  $(OBJ) -o $(NAME)

clean:
			@$(RM) $(OBJ)
			@echo // objekt files removed //

fclean:		clean
			@$(RM) $(NAME)
			@echo // all files removed //

re:			fclean all
			@echo // Clenad and rebuild everything! //

.PHONY:		all clean fclean re