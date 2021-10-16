NAME	= philo

HEADER	=	./philo.h

LIST	=	create_philo.c ft_atoi.c init.c parser.c philo.c time.c utils.c

OBJS	=	$(LIST:.c=.o)

CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror -I.

.PHONY	: all clean fclean re bonus

all	: $(NAME)

$(NAME)	: $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread

$(OBJS)	: $(HEADER)

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all