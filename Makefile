# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 10:31:02 by ccoupez           #+#    #+#              #
#    Updated: 2018/06/06 15:55:15 by ccoupez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ =	$(OBJ_ALL)\
		$(OBJ_CH)\
		$(OBJ_PS)\

OBJ_GEN = $(SRC_GEN:.c=.o)

OBJ_CH = $(SRC_CH:.c=.o)

OBJ_PS = $(SRC_PS:.c=.o)


CC = @gcc

SRC =	$(SRC_GEN)\
		$(SRC_CH)\
		$(SRC_PS)\

SRC_NAME_GEN =	manage_list.c \
				create_tab.c \
				swap_and_push_rules.c \
				rotate_rules.c \
				reverse_rotate_rules.c \

SRC_NAME_CH =	checker.c\

SRC_NAME_PS =	main.c \
				push_swap.c\
				pivot_choice.c\
				opti_sort.c\
				little_sort.c\

SRC_GEN = $(addprefix sources/,$(SRC_NAME_GEN))

SRC_CH = $(addprefix sources/,$(SRC_NAME_CH))

SRC_PS = $(addprefix sources/,$(SRC_NAME_PS))

NAME1 = checker

NAME2 = push_swap

LIB_PATH = libft/

LIB = libft/libft.a

INCLUDE = -I ./includes

CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

all: libftcomp $(NAME1) $(NAME2)

$(NAME1): $(LIB) $(OBJ_CH) $(OBJ_GEN)
	@gcc -o $(NAME1) $(CFLAGS) $(LIB) $(OBJ_CH) $(OBJ_GEN)
	@echo "\033[1;32mSucceed checker\033[0m"  

$(NAME2): $(LIB) $(OBJ_PS) $(OBJ_GEN)
	@gcc -o $(NAME2) $(CFLAGS) $(LIB) $(OBJ_PS) $(OBJ_GEN)
	@echo "\033[1;32mSucceed push_swap\033[0m"

libftcomp:
	@make -C $(LIB_PATH)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ_CH) $(OBJ_PS) $(OBJ_GEN)
	@echo "\033[1;32mSucceed clean checker objects\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@echo "\033[1;32mSucceed clean of libftprintf.a\033[0m"
	@rm -f $(NAME1) $(NAME2)
	@echo "\033[1;32mSucceed clean checker and push swap\033[0m"

re: fclean	all
	@echo "\033[1;32mSucceed recompilation checker\033[0m"
