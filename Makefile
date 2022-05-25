##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FreeKOSOVO
##

SRC     	=		$(addsuffix .c,						\
						$(addprefix src/,				\
							$(addprefix utils/,			\
								my_getenv				\
								my_get_line_env 		\
							)							\
							$(addprefix exec/,			\
								check_access			\
								check_crash				\
								check_path				\
								error_execve			\
								gettype 				\
							)					 		\
							$(addprefix alias/,			\
								if_alias_ll				\
								manage_alias			\
							)					 		\
							$(addprefix builtins/,		\
								$(addprefix cd/,		\
									error_cd			\
									pwd					\
									cd 					\
								)						\
								$(addprefix setenv/,	\
									my_setenv			\
									error_setenv		\
									error_setenv2 		\
								)						\
								if_builtins				\
								my_unsetenv				\
								exit					\
								manage_builtins 		\
							)							\
							error						\
							mysh						\
							ctrl_c						\
							redirection					\
							manage_commands				\
							pipe						\
							main 						\
						) 								\
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
							)							\
							$(addprefix exec/,			\
								check_access			\
								check_crash				\
								check_path				\
								error_execve			\
								gettype 				\
							)							\
							$(addprefix builtins/,		\
								$(addprefix cd/,		\
									error_cd			\
									pwd					\
									cd 					\
								)						\
								$(addprefix setenv/,	\
									my_setenv			\
									error_setenv		\
									error_setenv2 		\
								)						\
								if_builtins				\
								my_unsetenv				\
								exit					\
								manage_builtins 		\
							)							\
							error						\
							redirection					\
							pipe						\
							manage_commands				\
							ctrl_c 						\
						)								\
					)

OBJ     	=       $(SRC:.c=.o)

CC			=		gcc

CFLAGS		=		-Wall -Wextra

RM			=		rm -f

PATH_LIB	=		lib/my/

LDFLAGS		=		-L$(PATH_LIB) -lmy

NAME    	=		42sh

NAME_TEST	=		unit_tests

CPPFLAGS 	= 		-I ./include

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
