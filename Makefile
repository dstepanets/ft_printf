# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dstepane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 15:25:18 by dstepane          #+#    #+#              #
#    Updated: 2019/01/17 15:25:19 by dstepane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = ./ft_printf.h
SRCS =	ft_printf.c \
		parser.c \
		convert_c_s.c

LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft
	@echo "\033[32mLibft compiled.\033[0m"

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS)
	@echo "\033[32mft_printf object files compiled.\033[0m"

$(NAME): $(LIBFT) $(OBJS)
	ar -rc $(NAME) $(OBJS) $(HEAD) $(LIBFT)
	@echo "\033[32mlft_printf.a compiled.\033[0m"
	ranlib $(NAME)
	@echo "\033[32mft_printf.a indexed.\033[0m"

clean:
	rm -f $(OBJS)
	@echo "\033[31mft_printf object files removed.\033[0m"
	@make clean -C libft

fclean: clean
	rm -f $(NAME) $(LIBFT)
	@echo "\033[31mft_printf.a and libft.a removed.\033[0m"

re: fclean all
