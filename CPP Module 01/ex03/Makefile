NAME		=	Violence

HEADERS		=	Weapon.hpp\
				HumanA.hpp\
				HumanB.hpp

SRCS		=	main.cpp\
				Weapon.cpp\
				HumanA.cpp\
				HumanB.cpp

OBJS		=	$(SRCS:.cpp=.o)

FLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

%.o:%.cpp	$(HEADERS)
			g++ $(FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADERS)
			g++ $(FLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re