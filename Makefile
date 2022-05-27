##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FreeKOSOVO
##

SRC			=		$(addsuffix .c,						\
						$(addprefix src/,				\
							$(addprefix utils/,			\
								my_getenv				\
								my_get_line_env 		\
								my_clean_str			\
							)							\
							$(addprefix exec/,			\
								check_access			\
								check_crash				\
								check_path				\
								error_execve			\
								gettype					\
							)					 		\
							$(addprefix alias/,			\
								parsing_alias			\
								cmp_alias_and_cmd		\
								manage_alias			\
								manage_tmp_alias		\
								copy_file_in_directory	\
								find_alias_shrc			\
								search_tmp_shrc			\
								delete_and_add_alias	\
							)					 		\
							$(addprefix builtins/,		\
								$(addprefix cd/,		\
									error_cd			\
									pwd					\
									cd					\
								)						\
								$(addprefix setenv/,	\
									my_setenv			\
									error_setenv		\
									error_setenv2		\
								)						\
								$(addprefix history/,	\
									my_history			\
									my_clean_file		\
									my_print_file		\
								)						\
								if_builtins				\
								if_builtins_2			\
								my_unsetenv				\
								exit					\
								manage_builtins			\
							)							\
							$(addprefix redirection/,	\
								redirection				\
								redirection_left		\
								redirection_right		\
							)							\
							error						\
							mysh						\
							my_prompt					\
							ctrl_c						\
							manage_commands				\
							pipe						\
							main						\
						)								\
					)

SRC_TEST	=		$(addsuffix .c,						\
						$(addprefix tests/,				\
							tests_unit_access			\
							tests_unit_setenv			\
							tests_unit_cd				\
							tests_unit_mysh				\
							tests_error					\
						)								\
						$(addprefix src/,				\
							$(addprefix utils/,			\
								my_getenv				\
								my_get_line_env 		\
								my_clean_str			\
							)							\
							$(addprefix exec/,			\
								check_access			\
								check_crash				\
								check_path				\
								error_execve			\
								gettype					\
							)							\
							$(addprefix redirection/,	\
								redirection				\
								redirection_left		\
								redirection_right		\
							)							\
							$(addprefix builtins/,		\
								$(addprefix cd/,		\
									error_cd			\
									pwd					\
									cd					\
								)						\
								$(addprefix setenv/,	\
									my_setenv			\
									error_setenv		\
									error_setenv2		\
								)						\
								if_builtins				\
								my_unsetenv				\
								exit					\
								manage_builtins 		\
							)							\
							$(addprefix alias/,			\
								parsing_alias			\
								cmp_alias_and_cmd		\
								manage_alias			\
								copy_file_in_directory	\
								find_alias_shrc			\
								manage_tmp_alias		\
							)					 		\
							error						\
							my_prompt					\
							ctrl_c						\
							manage_commands				\
							pipe						\
						) 								\
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

debug:	CFLAGS += -g
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
