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
LIB_SRC =	ft_bzero.c \
			ft_isdigit.c \
			ft_memset.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_strncpy.c \
			ft_memmove.c \
			ft_strdup.c \
			ft_strncmp.c

LIB = $(addprefix $(LIB_DIR), $(LIB_SRC))

OBJS = $(SRCS:.c=.o) $(LIB_SRC:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) $(HEAD)
	@echo "\033[32mlibftprintf.a compiled.\033[0m"
	ranlib $(NAME)
	@echo "\033[32mlibftprintf.a indexed.\033[0m"

$(OBJS):
	$(CC) $(FLAGS) -c $(SRCS) $(LIB) 
	@echo "\033[32mft_printf object files compiled.\033[0m"

clean:
	rm -f $(OBJS)
	@echo "\033[31mft_printf object files removed.\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[31mlibftprintf.a removed.\033[0m"

re: fclean all
