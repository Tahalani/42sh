##
## EPITECH PROJECT, 2022
## 42sh
## File description:
## Makefile
##

SRC			=		$(addsuffix .c,							\
						$(addprefix src/,					\
							$(addprefix utils/,				\
								my_getenv					\
								my_get_line_env 			\
								my_clean_str				\
							)								\
							$(addprefix exec/,				\
								check_access				\
								check_crash					\
								check_path					\
								error_execve				\
								gettype						\
							)					 			\
							$(addprefix condition/,			\
								if_flag						\
								if							\
							)								\
							$(addprefix redirection/,		\
								redirection					\
								redirection_left			\
								redirection_right			\
							)								\
							$(addprefix builtins/,			\
								$(addprefix cd/,			\
									error_cd				\
									pwd						\
									cd						\
								)							\
								$(addprefix echo/,			\
									print_echo_if_arg		\
									my_echo					\
									echo_handle_backslash	\
									verif_echo_arg			\
									if_backslash_2			\
									if_backslash			\
								)							\
								$(addprefix setenv/,		\
									my_setenv				\
									error_setenv			\
									error_setenv2			\
								)							\
								$(addprefix history/,		\
									my_history				\
									my_clean_file			\
									my_print_file			\
								)							\
								if_builtins					\
								if_builtins_2				\
								my_unsetenv					\
								exit						\
								manage_builtins				\
							)								\
							$(addprefix variables/,			\
								manage_variables			\
								exec_variables				\
								search_variables_exist		\
								mem_alloc_var				\
								print_var_exists			\
							)								\
							$(addprefix alias/,				\
								parsing_alias				\
								cmp_alias_and_cmd			\
								manage_alias				\
								copy_file_in_directory		\
								find_alias_shrc				\
								manage_tmp_alias			\
								delete_and_add_alias		\
								search_tmp_shrc				\
							)					 			\
							error							\
							mysh							\
							my_prompt						\
							ctrl_c							\
							manage_commands					\
							pipe							\
							main							\
						)									\
					)

SRC_TEST	=		$(addsuffix .c,							\
						$(addprefix src/,					\
							$(addprefix utils/,				\
								my_getenv					\
								my_get_line_env 			\
								my_clean_str				\
							)								\
							$(addprefix exec/,				\
								check_access				\
								check_crash					\
								check_path					\
								error_execve				\
								gettype						\
							)					 			\
							$(addprefix redirection/,		\
								redirection					\
								redirection_left			\
								redirection_right			\
							)								\
							$(addprefix builtins/,			\
								$(addprefix cd/,			\
									error_cd				\
									pwd						\
									cd						\
								)							\
								$(addprefix echo/,			\
									print_echo_if_arg		\
									my_echo					\
									echo_handle_backslash	\
									verif_echo_arg			\
									if_backslash_2			\
									if_backslash			\
								)							\
								$(addprefix setenv/,		\
									my_setenv				\
									error_setenv			\
									error_setenv2			\
								)							\
								$(addprefix history/,		\
									my_history				\
									my_clean_file			\
									my_print_file			\
								)							\
								if_builtins					\
								if_builtins_2				\
								my_unsetenv					\
								exit						\
								manage_builtins				\
							)								\
							$(addprefix variables/,			\
								manage_variables			\
								exec_variables				\
								search_variables_exist		\
								mem_alloc_var				\
								print_var_exists			\
							)								\
							$(addprefix alias/,				\
								parsing_alias				\
								cmp_alias_and_cmd			\
								manage_alias				\
								copy_file_in_directory		\
								find_alias_shrc				\
								manage_tmp_alias			\
								delete_and_add_alias		\
								search_tmp_shrc				\
							)					 			\
							error							\
							mysh							\
							my_prompt						\
							ctrl_c							\
							manage_commands					\
							pipe							\
						)									\
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
