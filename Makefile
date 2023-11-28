SRCS =  ft_printf.c \
		ft_printchar.c \
		ft_printstring.c \
		ft_printnum.c \
		ft_printpointer.c \
		ft_print_hex.c

#SRCSBONUS = 
 			
OBJS = ${SRCS:.c=.o}
#OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = libftprintf.a
HEADER = ft_printf.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Metodo Implicito --------------------------------------
%.o:%.c 	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

# Mis metodos --------------------------------------------
all: 		${NAME}

${NAME}:	${OBJS} ${HEADER}
			ar rcs $@ $?

#bonus:		${OBJS} ${OBJSBONUS}
#			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
#			@touch $@

clean: 		
			${RM} ${OBJS}
#			${RM} ${OBJS} ${OBJSBONUS}

#			re-make (do as if it was the first time)
fclean: 	clean
			${RM} ${NAME}
#			${RM} bonus

re:			fclean all

# Esto es para decir que metodos no tiene que confundir con archivos 
.PHONY: all clean fclean re
