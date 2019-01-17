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

.PHONY: all clean fclean re

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = ./ft_printf.h
SRCS =	ft_printf.c \
		parser.c \
		convert_c_s.c
LIB_DIR = ./pf_libft/
LIB_SRC =	ft_bzero.c \
			ft_isdigit.c \
			ft_memset.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strsub.c
LIB = $(addprefix $(LIB_DIR), $(LIB_SRC))
OBJS = $(SRCS:.c=.o) $(LIB_SRC:.c=.o)


re: fclean all

all: $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS) $(LIB) 
	@echo "\033[32mft_printf object files compiled.\033[0m"

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) $(HEAD)
	@echo "\033[32mft_printf.a compiled.\033[0m"
	ranlib $(NAME)
	@echo "\033[32mft_printf.a indexed.\033[0m"
	$(CC) -g main.c $(NAME)
	@echo "\033[32ma.out compiled\033[0m"
	rm -f $(OBJS)
	@echo "\033[31mft_printf object files removed.\033[0m"
clean:
	rm -f $(OBJS)
	@echo "\033[31mft_printf object files removed.\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31mft_printf.a removed.\033[0m"
	rm -Rf ./a.out a.out.dSYM		#a.out a.out.dSYM !!!TO DELETE
	@echo "\033[31ma.out removed.\033[0m"

####################TO DELETE##########################
#b: all clean
#	$(CC) -g main.c $(NAME)
#	@echo "\033[32ma.out compiled\033[0m"
#
#bw: all clean
#	$(CC) $(FLAGS) -g main.c $(NAME)
#	@echo "\033[32ma.out compiled with -W flags.\033[0m"
######################################################