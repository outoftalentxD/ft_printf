NAME = libftprintf.a

SRCS = parser/ft_gettype.c \
	   parser/ft_getwidth.c \
	   parser/ft_getprecision.c \
	   parser/ft_getflags.c \
	   parser/ft_format_parse.c \
	   parser/ft_ptypes.c \
	   parser/ft_utils.c \
	   core/ft_printf.c \
	   core/ft_handler.c \
	   core/ft_process_str.c \
	   core/ft_process_char.c \
	   core/ft_process_int.c \
	   core/ft_process_base.c \
	   core/ft_process_ptr.c \
	   core/ft_process_perc.c \
	   core/ft_process_uint.c \
	   core/ft_tools.c \
	   core/ft_writers.c

OBJS = ${SRCS:.c=.o}

INCLUDE = includes

DEPENDENCES = 	includes/ft_printf.h \
		  		includes/ft_parser.h \
		  		includes/ft_struct.h \
				libft/libft.h


L_DIR = libft

L_NAME = libft.a

L_PATH = libft/libft.a

CC = gcc

CFLAGS = -Wextra -Wall -Werror 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDE}

all: ${NAME} ${OBJD}

$(NAME):	${OBJS} ${DEPENDENCES}
			$(MAKE) -C ${L_DIR}
			mv ${L_PATH} ${NAME}
			ar rc ${NAME} ${OBJS}	
			
clean:
	$(MAKE) clean -C ${L_DIR}
	rm -f ${OBJS}

fclean: clean
		rm -f ${NAME} 

re: fclean all
