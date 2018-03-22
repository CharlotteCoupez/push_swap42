# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoupez <ccoupez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 10:48:55 by ccoupez           #+#    #+#              #
#    Updated: 2018/02/28 12:21:18 by ccoupez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS_PATH = sources
SRCS_NAME =	main.c \
			checker.c \
			swap_and_push_rules.c \
			rotate_rules.c \
			reverse_rotate_rules.c

SRCS = $(addprefix $(SRCS_PATH)/,$(SRCS_NAME))
 
OBJS = $(SRCS:.c=.o)

INCLUDE = -I ./include

CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
LIB = libft/libft.a
	
.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): libftcomp $(OBJS) $(LIB)
	gcc $(CFLAGS) -c $(SRCS)
	gcc -o $(NAME) -Wall -Werror -Wextra $(LIB) $(OBJS)
	@echo "\033[32;1mCompilation completed!\033[0m"

libftcomp:
	@make all -C libft/

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@rmdir $(OBJS_PATH) 2> /dev/null || true
	@echo "\033[32;2m Cleaned successfully!\033[0m"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@echo "\033[32;2m Fcleaned successfully!\033[0m"

re: fclean all
	@echo "\033[1;32mSucced recompilation!\033[0m"