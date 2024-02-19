SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
		  ar -rcs ${NAME} ${OBJS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean :	
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all