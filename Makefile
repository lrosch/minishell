CC:= gcc

NAME:= minishell

CFLAGS+= -Wall -Werror -Wextra

SRC:=	minishell.c redirections/handle_in_red.c redirections/handle_out_red.c \
		redirections/here_doc.c utils/free.c initialize.c signal.c prompt.c \
		utils/lst_utils.c builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c  \
		builtins/pwd.c builtins/unset.c builtins/export.c utils/minishell_utils.c \
		parsing/parsing.c parsing/split_args.c parsing/split_cmd.c utils/quote_checking.c \
		parsing/variable_expansion.c utils/pipe_utils.c utils/error.c \
		input_handling/handle_builtins.c input_handling/handle_redirections.c \
		input_handling/build_cmd.c input_handling/handle_input.c utils/signal_utils.c \
		builtins/export2.c parsing/variable_expansion_util.c parsing/parsing_two.c \
		redirections/here_doc_help.c parsing/parsing_three.c input_handling/handle_input_help.c \
		redirections/here_doc_help2.c builtins/export3.c

OBJECTS:=  $(SRC:c=o)

LIBFTP:= libftplus.a

RDLINK:= -lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RDINC:= -I/Users/$(USER)/.brew/opt/readline/include

$(NAME): $(OBJECTS) | silence
	@make -C ./libftplus
	@cp libftplus/libftplus.a $(LIBFTP)
	@$(CC) $^ $(CFLAGS) -L. -lftplus $(RDLINK) $(RDINC) -o $@
	@printf "\n		successfully compiled \n\n"

%.o: %.c
	$(CC) $(RDINC) $< -c $(CFLAGS) -o $@

all: $(NAME)

silence:
	@:

clean:
	@find . -type f -name '*.o' -delete
	@make -C ./libftplus clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFTP)
	@make -C ./libftplus fclean

re: fclean
	@make -C ./libftplus fclean
	@make all

.PHONY: clean fclean re