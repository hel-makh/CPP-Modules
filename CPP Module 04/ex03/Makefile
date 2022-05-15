NAME		=	Game

HEADERS		=	ICharacter.hpp\
				Character.hpp\
				IMateriaSource.hpp\
				MateriaSource.hpp\
				AMateria.hpp\
				Ice.hpp\
				Cure.hpp

SRCS		=	main.cpp\
				Character.cpp\
				MateriaSource.cpp\
				AMateria.cpp\
				Ice.cpp\
				Cure.cpp

OBJS		=	$(SRCS:.cpp=.o)

FLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

%.o:%.cpp	$(HEADERS)
			c++ $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADERS)
			c++ $(FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
