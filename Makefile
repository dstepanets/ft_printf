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
		convert_c_percent.c \
		convert_s.c \
		convert_di.c \
		convert_di2.c \
		convert_u.c \
		convert_o.c \
		convert_x.c \
		convert_p.c \
		convert_f.c \
		convert_f2.c \
		convert_b.c \
		colors1.c \
		colors2.c \
		colors3.c \
		pf_itoa_base.c \
		pf_strjoin.c
LIB_DIR = ./pf_libft/
LIB_SRC = *.c
#	LIB_SRC =	ft_bzero.c \
#				ft_isdigit.c \
#				ft_memset.c \
#				ft_putstr.c \
#				ft_strchr.c \
#				pf_strjoin.c \
#				ft_strlen.c \
#				ft_strnew.c \
#				ft_strsub.c \
#				ft_putstr_fd.c \
#				ft_memdel.c \
#				ft_strncpy.c \
#				ft_strncat.c
LIB = $(addprefix $(LIB_DIR), $(LIB_SRC))
OBJS = $(SRCS:.c=.o) $(LIB_SRC:.c=.o)

re: fclean all

all: $(NAME)

$(OBJS):
	$(CC) $(FLAGS) -g -c $(SRCS) $(LIB) 
	@echo "\033[32mft_printf object files compiled.\033[0m"

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) $(HEAD)
	@echo "\033[32mft_printf.a compiled.\033[0m"
	ranlib $(NAME)
	@echo "\033[32mft_printf.a indexed.\033[0m"
	$(CC) -g main.c $(NAME)
	#$(CC) -g -fsanitize=address main.c $(NAME)
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

bw:
	$(CC) $(FLAGS) -g main.c $(NAME)
	@echo "\033[32ma.out compiled with -W flags.\033[0m"

####################TO DELETE##########################
#b: all clean
#	$(CC) -g main.c $(NAME)
#	@echo "\033[32ma.out compiled\033[0m"
#
#bw: all clean
#	$(CC) $(FLAGS) -g main.c $(NAME)
#	@echo "\033[32ma.out compiled with -W flags.\033[0m"
######################################################