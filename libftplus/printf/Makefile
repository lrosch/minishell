CC:= gcc

NAME:= printf.a

CFLAGS?= -Wall -Werror -Wextra

SRC:=	ft_printf.c helper.c check_instr.c check_valid_flags.c check_valid_flags_2.c \
		check_valid.c handlers.c printer.c printer_2.c

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