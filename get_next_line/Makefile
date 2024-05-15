SRCS = 	get_next_line.c \
		get_next_line_utils.c

BONUSSRC =		get_next_line.c \
				get_next_line_utils.c
OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUSSRC:.c=.o}
CC 			= gcc 
CFLAGS		= -Wall -Wextra -Werror
NAME 		= get_next_line.a

%.o: %.c
		${CC} -c $(CFLAGS) $?
	
all:		${NAME}

${NAME}:	${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
					rm -f ${OBJS} 

fclean:		clean
					rm -f ${NAME}

re:			fclean all

bonus:		${OBJS} ${BONUS_OBJS}
					ar rcs ${NAME} ${OBJS} ${BONUS_OBJS}


.PHONY:		all clean fclean re bonus