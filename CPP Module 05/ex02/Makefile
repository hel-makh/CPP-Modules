NAME		=	Forms

HEADERS		=	Bureaucrat.hpp\
				Form.hpp\
				ShrubberyCreationForm.hpp\
				RobotomyRequestForm.hpp\
				PresidentialPardonForm.hpp

SRCS		=	main.cpp\
				Bureaucrat.cpp\
				Form.cpp\
				ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp\
				PresidentialPardonForm.cpp

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