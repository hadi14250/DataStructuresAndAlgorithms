SRCS			= main.cpp bfs.cpp
					
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
RM				= rm -f
CXXFLAGS		= -std=c++17 -Wall -Wextra -Werror

NAME			= bfs

ARGS := $(filter-out $(firstword $(MAKECMDGOALS)),$(MAKECMDGOALS))

all:			$(NAME)

$(NAME):		$(OBJS)
				 $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)
					$(RM) $(OBJS)

exec: 			$(NAME)
					@./$(NAME) $(ARGS)

rexec: 			re
					@./$(NAME) $(ARGS)

%:
	@: