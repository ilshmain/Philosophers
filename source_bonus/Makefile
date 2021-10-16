NAME	= philo_bonus

HEADER	=	./philo_bonus.h

LIST	=	create_philo.c ft_atoi.c init.c parser.c philo.c time.c utils.c

OBJS	=	$(LIST:.c=.o)

CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror -I.

.PHONY	: all clean fclean re bonus

all	: $(NAME)

$(OBJS)	: $(HEADER)

$(NAME)	: $(HEADER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -pthread

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all