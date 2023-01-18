# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:43:06 by hrecolet          #+#    #+#              #
#    Updated: 2023/01/18 15:21:02 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g3
OBJS_DIR		=	.objs


#===================================================#
#						VECTOR						#
#===================================================#
VEC_SRCS		=	srcs/ft_vector/main.cpp\
					srcs/ft_vector/constructor.cpp\
					srcs/ft_vector/capacity.cpp\
					srcs/ft_vector/access.cpp\
					srcs/ft_vector/modifiers.cpp\

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

STACK_SRCS		=	srcs/ft_stack/stack.cpp\

STACK_OBJS 		= 	$(addprefix $(OBJS_DIR)/, $(notdir $(STACK_SRCS:%.cpp=%.o)))

$(OBJS_DIR)/%.o	: 	srcs/ft_stack/%.cpp
					@printf "\033[0;33mGenerating stack object... %-38.38s \r" $@
					@$(CC) $(CFLAGS) -c $< -o $@

stack			: 	$(OBJS_DIR) $(STACK_OBJS)
		      		@$(CC) $(CFLAGS) $(STACK_OBJS) -o stack
					@echo \n
					@echo "\033[1;32mStack: Done!\033[0m"

#===================================================#
#						MAP							#
#===================================================#

MAP_SRCS		=	srcs/ft_map/map.cpp\
					srcs/ft_map/map_capacity.cpp\
					srcs/ft_map/map_access.cpp\
					srcs/ft_map/map_modifier.cpp\
					srcs/ft_map/map_operations.cpp\

MAP_OBJS 		= 	$(addprefix $(OBJS_DIR)/, $(notdir $(MAP_SRCS:%.cpp=%.o)))

$(OBJS_DIR)/%.o	: 	srcs/ft_map/%.cpp
					@printf "\033[0;33mGenerating map object... %-38.38s \r" $@
					@$(CC) $(CFLAGS) -c $< -o $@

map				: 	$(OBJS_DIR) $(MAP_OBJS)
		      		@$(CC) $(CFLAGS) $(MAP_OBJS) -o map
					@echo \n
					@echo "\033[1;32mMap: Done!\033[0m"

#===================================================#
#						GENERAL						#
#===================================================#
all				:	map vector stack

clean			:
					@rm -rf $(OBJS_DIR)
					@echo "\033[1;31mObject cleaned!\033[0m"
					
fclean			:	
					@rm -rf $(OBJS_DIR)
					@rm -f vector
					@rm -f stack
					@rm -f map
					@echo "\033[1;31mProgram and object cleaned!\033[0m"

re				:	fclean all

.PHONY			:
					all clean fclean re vector stack map
