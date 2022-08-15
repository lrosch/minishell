CC:= gcc

NAME:= gnl.a

CFLAGS?= -Wall -Werror -Wextra

SRC:=	get_next_line.c get_next_line_utils.c

OBJECTS:= $(SRC:c=o)

$(NAME): $(OBJECTS) | silence

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

silence:
	@:

clean:
	@rm -f *.o

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re