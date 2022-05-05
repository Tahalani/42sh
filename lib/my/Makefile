##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FreeKOSOVO
##

SRC			=	$(addsuffix .c,					\
				$(addprefix my_,				\
					swap						\
					freef						\
					strcpy						\
					strlen						\
					strdup						\
					getnbr						\
					isneg						\
					putstr						\
					revstr						\
					strtok						\
					strcat						\
					strcmp						\
					strstr						\
					puterr						\
					strncat						\
					put_nbr						\
					showstr						\
					strncpy						\
					putchar						\
					showmem						\
					strncmp						\
					putnchar					\
					is_prime					\
					copy_tab					\
					str_isnum					\
					strupcase					\
					len_array					\
					char_isnum					\
					strlowcase					\
					free_array					\
					int_to_str					\
					file_in_str					\
					str_isalpha					\
					str_islower					\
					str_isupper					\
					get_line_tab				\
					char_isupper				\
					char_islower				\
					char_isalpha				\
					putchar_error				\
					strcapitalize				\
					write_in_file				\
					char_is_in_str				\
					sort_int_array				\
					find_prime_sup				\
					replace_in_tab				\
					stwa_separator				\
					strcat_in_array				\
					show_word_array				\
					str_isprintable				\
					count_char_in_str			\
					char_is_printable			\
					compute_power_rec			\
					char_is_alpha_num			\
					str_to_word_array			\
					get_first_line_file			\
					compute_square_root			\
					malloc_2d_char_array))

SRC_PRINTF	=	$(addsuffix .c,					\
				$(addprefix my_printf/,			\
					my_printf					\
					my_putlong					\
					sum_numbers					\
					my_putnbr_base				\
					my_put_special				\
					sum_strings_length))

OBJ				=	$(SRC:.c=.o)

OBJ_PRINTF		=	$(SRC_PRINTF:.c=.o)

NAME			=	libmy.a

CC				=	gcc

MKDIR			=	mkdir -p

AR				=	ar rc

CFLAGS			=	-Wall -Wextra

RM				=	rm -f

INCLUDE_NAME	=	my.h

PATH_INCLUDE	=	./../../include/my.h

all:	$(NAME)

debug:	CFLAGS += -g3
debug:	re

$(NAME):	$(OBJ)	$(OBJ_PRINTF) $(PATH_INCLUDE)
	$(AR) $(NAME) $(OBJ) $(OBJ_PRINTF)

$(PATH_INCLUDE):
	$(MKDIR) ./../../include
	cp $(INCLUDE_NAME) $(PATH_INCLUDE)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_PRINTF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all	clean	fclean	re	debug	$(PATH_INCLUDE)
