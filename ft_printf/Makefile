SRCS		= $(shell find "." -name "*c" ! -name "ft_lst*.c")
BONUSES 	= $(shell find "." -name "*ft_lst*.c")
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS  = ${BONUSES:.c=.o}
NAME		= lftprintf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${AR} libft.a ${OBJS}

 bonus : ${BONUS_OBJS}
	${AR} lftprintf.a ${BONUS_OBJS}


all : ${NAME}

clean :
	${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o

