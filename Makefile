SRCS		= $(shell find "./srcs" -name "*c")
OBJS		= ${SRCS:.c=.o}
LIBFT		= ./libft/libft.a
NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	$(MAKE) -C ./libft
	cp $(LIBFT) ${NAME}
	${AR} libftprintf.a ${OBJS}

all : ${NAME}

clean :
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean : clean
	$(MAKE) clean -C ./libft
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o

