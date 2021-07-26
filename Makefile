
LIBFT	= libft

NAME	= libftprintf.a

MAIN	= main.c

SRCS	= ft_printf.c \
			ft_utils.c \
			ft_utils_hex.c \
			ft_utils_int.c \
			ft_utils_recycle.c \

OBJS	= ${SRCS:.c=.o}

TESTLIB	= -L./libft -lft

INC	= ft_printf.h

CFLAGS	= -Wall -Wextra -Werror

CC	= gcc

all:		${NAME}

${NAME}:	${OBJS}
		make -C ${LIBFT}
		cp ${LIBFT}/libft.a ./${NAME}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

%.o:		%.c ${INC}
		${CC} ${CFLAGS} -c ${SRCS} -I ${INC}
		

test:
		${CC} ${CFLAGS} ${MAIN} ${SRCS} ${TESTLIB} -I ${INC} -o test.out -g -fsanitize=address

clean:		
		rm -rf ${OBJS}

fclean:		clean
		rm -rf ./*.a
		rm -rf ./*.out*
		rm -rf ./libft/*.out*
		rm -rf ./libft/*.o

re:		fclean all

.PHONY: all clean fclean re test