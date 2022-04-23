NAME		=	Zombie

HEADERS		=	Zombie.hpp

SRCS		=	main.cpp\
				Zombie.cpp\
				newZombie.cpp\
				randomChump.cpp

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