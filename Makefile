# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:43:06 by hrecolet          #+#    #+#              #
#    Updated: 2022/12/01 12:23:06 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
OBJS_DIR		=	.objs


#===================================================#
#						VECTOR						#
#===================================================#
VEC_SRCS		=	srcs/ft_vector/main.cpp\
					srcs/ft_vector/constructor.cpp\
					srcs/ft_vector/capacity.cpp\

VEC_OBJS 		= 	$(addprefix $(OBJS_DIR)/, $(notdir $(VEC_SRCS:%.cpp=%.o)))

$(OBJS_DIR)		:
					@mkdir -p $(OBJS_DIR)


$(OBJS_DIR)/%.o	: 	srcs/ft_vector/%.cpp
					@printf "\033[0;33mGenerating vector object... %-38.38s \r" $@
					@$(CC) $(CFLAGS) -c $< -o $@

vector			: 	$(OBJS_DIR) $(VEC_OBJS)
		      		@$(CC) $(CFLAGS) $(VEC_OBJS) -o vector
					@echo \n
					@echo "\033[1;32mVector: Done!\033[0m"

#===================================================#
#						STACK						#
#===================================================#

#===================================================#
#						MAP							#
#===================================================#

#===================================================#
#						GENERAL						#
#===================================================#
all				:	vector

clean			:
		      		@rm -f $(VEC_OBJS)
					@rm -rf $(OBJS_DIR)
					@echo "\033[1;31mObject cleaned!\033[0m"
					
fclean			:	
					@rm -f $(VEC_OBJS)
					@rm -rf $(OBJS_DIR)
					@rm -f vector
					@echo "\033[1;31mProgram and object cleaned!\033[0m"

re				:	fclean all

.PHONY			:
					all clean fclean re
