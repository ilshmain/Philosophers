NAME		=	pipex

NAMEB		=	pipex_bonus

SRCS_FILES	= 	${shell find ./source -name "*.c"}

BONUS_FILES	= 	${shell find ./source_bonus -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
SRCS_UTILS_FILES	=	$(BONUS_FILES)
OBJS_UTILS		=	$(patsubst %.c,%.o,$(SRCS_UTILS_FILES))

LIB_DIR		=	libft
INCLUDE		=	include/pipex.h

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

.PHONY:		all clean fclean re

all:		$(NAME)

%.o:		%.c $(INCLUDE) libft/libft.h libft/*.c
			$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@
		
$(NAME):	$(OBJS) $(INCLUDE)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -I./include -o $(NAME)

bonus:		$(NAMEB)

$(NAMEB):	$(OBJS_UTILS) $(INCLUDE)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(OBJS_UTILS) $(LIB_DIR)/libft.a -I./include -o $(NAMEB)

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS) $(OBJS_UTILS)
			

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME) $(NAMEB)

re:			fclean all