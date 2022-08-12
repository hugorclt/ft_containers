# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:43:06 by hrecolet          #+#    #+#              #
#    Updated: 2022/07/13 12:06:43 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/ft_stack.cpp	\
				srcs/ft_map.cpp		\
				srcs/ft_vector.cpp

OTH_SRCS	=	includes/iterator.hpp	\

DIR_OBJS	=	.objs

OBJS		=	$(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.c=.o)))

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror  -fsanitize=address -g3 -std=c++98

all			:	stack vector map

#==========================STACK=========================#

STACK		=	ft_stack

stack		:	$(STACK)

$(STACK)	:	./objs/ft_stack.o
				@$(CC) $(CFLAGS) -o $@ $<
				
#==========================VECTOR========================#

VECTOR		=	ft_vector

vector		:	$(VECTOR)

$(VECTOR)	:	./objs/ft_vector.o
				$(CC) $(CFLAGS) -o $@ $<

#============================MAP=========================#

MAP			=	ft_map

map			:	$(MAP)

$(MAP)		:	./objs/ft_map.o
				@$(CC) $(CFLAGS) -o $@ $<

#=========================OBJS==========================#

./objs/ft_vector.o	:	srcs/ft_vector.cpp includes/ft_vector.hpp $(OTH_SRCS)
						@mkdir -p objs
						$(CC) $(CFLAGS) -o $@ -c $<

./objs/ft_stack.o	:	srcs/ft_stack.cpp includes/ft_stack.hpp $(OTH_SRCS)
						@mkdir -p objs
						@$(CC) $(CFLAGS) -o $@ -c $<

./objs/ft_map.o		:	srcs/ft_map.cpp includes/ft_map.hpp $(OTH_SRCS)
						@mkdir -p objs
						@$(CC) $(CFLAGS) -o $@ -c $<
						@clear
						@echo "Compilation done!"

clean		:	
				@rm -rf ./objs/
				@echo "Cleaned"

fclean		:	clean
				@clear
				@rm	-f	$(VECTOR)
				@rm	-f	$(MAP)
				@rm	-f	$(STACK)
				@echo "Fully cleaned"

re			:	fclean all

.PHONY		:	all clean fclean re stack vector map
