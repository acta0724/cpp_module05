NAME = Intern

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AForm.cpp Bureaucrat.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)
SHRUBBERY = home.shrubbery

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(SHRUBBERY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
