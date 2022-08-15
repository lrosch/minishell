NAME:= libftplus.a

CFLAGS?= -Wall -Werror -Wextra

${NAME}: | silence
	@make -C ./libft
	@ar rc ${NAME} libft/*.o
	@make -C ./gnl
	@ar rc ${NAME} gnl/*.o
	@make -C ./printf
	@ar rc ${NAME} printf/*.o

all: $(NAME)

silence:
	@:

clean:
	@make -C ./libft clean
	@make -C ./gnl clean
	@make -C ./printf clean

fclean: clean
	@rm -f ${NAME}
	@make -C ./libft fclean
	@make -C ./gnl fclean
	@make -C ./printf fclean

re: fclean
	@make -C ./libft fclean
	@make -C ./gnl fclean
	@make -C ./printf fclean
	@make all

.PHONY: clean fclean re