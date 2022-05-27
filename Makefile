##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FreeKOSOVO
##

SRC     	=		$(addsuffix .c,							\
						$(addprefix src/,					\
							$(addprefix exec/,				\
								check_access				\
								check_crash					\
								check_path					\
								error_execve				\
								gettype 					\
							)					 			\
							$(addprefix builtins/,			\
								$(addprefix cd/,			\
									error_cd				\
									pwd						\
									cd 						\
								)							\
								$(addprefix setenv/,		\
									my_setenv				\
									error_setenv			\
									error_setenv2 			\
								)							\
								$(addprefix echo/,			\
									print_echo_if_arg		\
									my_echo					\
									echo_handle_backslash	\
									verif_echo_arg			\
									if_backslash_2			\
									if_backslash			\
								)							\
								if_builtins					\
								if_builtins_2				\
								my_unsetenv					\
								exit						\
								manage_builtins 			\
								)							\
								$(addprefix redirection/,	\
									redirection_left		\
									redirection_right		\
									redirection				\
								)							\
								$(addprefix utils/,			\
									my_clean_str			\
									my_get_line_env			\
									my_getenv				\
								)							\
							error							\
							mysh							\
							ctrl_c							\
							my_prompt						\
							manage_commands					\
							pipe							\
							main 							\
						) 									\
					)

SRC_TEST	=		$(addsuffix .c,							\
						$(addprefix tests/,					\
							tests_unit_access				\
							tests_unit_setenv				\
							tests_unit_cd					\
							tests_unit_mysh					\
							tests_error						\
						)									\
						$(addprefix src/,					\
							$(addprefix exec/,				\
								check_access				\
								check_crash					\
								check_path					\
								error_execve				\
								gettype 					\
							)					 			\
							$(addprefix builtins/,			\
								$(addprefix cd/,			\
									error_cd				\
									pwd						\
									cd 						\
								)							\
								$(addprefix setenv/,		\
									my_setenv				\
									error_setenv			\
									error_setenv2 			\
								)							\
								$(addprefix echo/,			\
									print_echo_if_arg		\
									my_echo					\
									echo_handle_backslash	\
									verif_echo_arg			\
									if_backslash_2			\
									if_backslash			\
								)							\
								if_builtins					\
								if_builtins_2				\
								my_unsetenv					\
								exit						\
								manage_builtins 			\
								)							\
								$(addprefix redirection/,	\
									redirection_left		\
									redirection_right		\
									redirection				\
								)							\
								$(addprefix utils/,			\
									my_clean_str			\
									my_get_line_env			\
									my_getenv				\
								)							\
							error							\
							mysh							\
							ctrl_c							\
							my_prompt						\
							manage_commands					\
							pipe							\
						) 									\
					)

OBJ			=		$(SRC:.c=.o)

CC			=		gcc

CFLAGS		=		-Wall -Wextra

RM			=		rm -f

PATH_LIB	=		lib/my/

LDFLAGS		=		-L$(PATH_LIB) -lmy

NAME		=		42sh

NAME_TEST	=		unit_tests

CPPFLAGS	=		-I ./include

COVFLAGS	=		--coverage -lcriterion -lgcov

COVFILES	=		*.gcno *.gcda

all:	$(NAME)

debug:	CFLAGS += -g3
debug:	fclean $(OBJ)
	make debug -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(MAKE) clean -C $(PATH_LIB)
	$(RM) $(OBJ)
	$(RM) $(NAME_TEST)
	$(RM) $(COVFILES)

fclean: clean
	$(MAKE) fclean -C $(PATH_LIB)
	$(RM) $(NAME)

re: fclean all

tests_run: fclean
	$(MAKE) -C $(PATH_LIB)
	$(CC) -o $(NAME_TEST) $(CPPFLAGS) $(CFLAGS) $(SRC_TEST) $(LDFLAGS)	\
	$(COVFLAGS)
	./$(NAME_TEST)
	gcovr --exclude tests
	gcovr --branches --exclude tests

.PHONY:	all	debug	clean	fclean	re	tests_run
