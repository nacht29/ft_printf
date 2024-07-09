NAME = libftprintf.a
TESTNAME = printf.exe

SRC = 	ft_printf.c ft_strlen.c \
		putchr.c putstr.c \
		putnbr.c put_uint.c puthex.c\
		putptr.c
	  
OBJS = $(SRC:.c=.o)

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror

all: $(NAME)

test: $(TESTNAME)

$(NAME): $(OBJS)
	@ar rcs ${NAME} ${OBJS}

$(TESTNAME):
	$(CC) $(CFLAGS) $(SRC) main.c -o $(TESTNAME) && ./$(TESTNAME)

clean:
	@$(RM) *.o
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(TESTNAME)
	@clear

re: fclean all

.PHONY: all test clean fclean re