NAME = libftprintf.a

SRC = 	ft_printf.c ft_strlen.c \
		putchr.c putstr.c \
		putnbr.c put_uint.c puthex.c\
		putptr.c
	  
OBJS = $(SRC:.c=.o)

CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs ${NAME} ${OBJS}

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
