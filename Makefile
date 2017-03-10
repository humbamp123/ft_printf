# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apineda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 14:15:48 by apineda           #+#    #+#              #
#    Updated: 2017/03/08 14:15:50 by apineda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

FILENAMES = ft_printf.c ft_libfunct_1.c ft_libfunct_2.c 
INCLUDE_DIR = ./includes

CC = gcc
AR = AR

CCFLAGS = -Wall -Wextra -Werror
INC = -I $(INCLUDE_DIR)

SOURCES_1 = $(addprefix srcs/, $(FILENAMES))
OBJECTS_1 = $(addprefix objs/, $(FILENAMES:.c=.o))

all: $(NAME)

$(NAME): $(OBJECTS_1)
	@$(AR) rc $@ $^
	@ranlib $@
	@echo "libftprintf compiled!"

objs:
	@mkdir $@

objs/%.o: srcs/%.c | objs
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf objs

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean