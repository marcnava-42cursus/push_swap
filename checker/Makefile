# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:45:51 by marcnava          #+#    #+#              #
#    Updated: 2025/02/28 19:01:58 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	checker

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./includes

# **************************************************************************** #
#		FOLDERS	#

SRCSPATH	=	./src
BUILD		=	./build

# **************************************************************************** #
#		FILES	#

SRCS 		=	$(SRCSPATH)/checker.c

OBJS		=	$(SRCS:$(SRCSPATH)/%.c=$(BUILD)/%.o)

# **************************************************************************** #
#		RULES	#

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) $(INCLUDE) -o $(NAME) $(OBJS)

$(BUILD)/%.o: $(SRCSPATH)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(BUILD)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re