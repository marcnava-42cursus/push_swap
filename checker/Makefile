# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 18:45:51 by marcnava          #+#    #+#              #
#    Updated: 2025/03/01 19:34:16 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	checker

CC			=	cc
RM			=	rm -rf

# CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./includes

# **************************************************************************** #
#		FOLDERS	#

SRCSPATH	=	./src
BUILD		=	./build

LIBFT		=	./libs/libft

INSTRPATH	=	./src/instructions

# **************************************************************************** #
#		FILES	#

UTILS 		=	$(SRCSPATH)/checker_bonus.c \
				$(SRCSPATH)/utils_bonus.c

INSTRUCTIONS=	$(INSTRPATH)/swap_bonus.c \
				$(INSTRPATH)/push_bonus.c \
				$(INSTRPATH)/rotate_bonus.c \
				$(INSTRPATH)/rrotate_bonus.c

SRCS		=	$(UTILS) $(INSTRUCTIONS)

OBJS		=	$(SRCS:$(SRCSPATH)/%.c=$(BUILD)/%.o)

# **************************************************************************** #
#		RULES	#

bonus: $(LIBFT)/libft.a $(NAME)
.PHONY: bonus

$(NAME): $(OBJS)
	@$(COMPILER) $(INCLUDE) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
	@$(MAKE) --no-print-directory -s -C $(LIBFT)

$(BUILD)/%.o: $(SRCSPATH)/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(BUILD)
	@$(MAKE) --no-print-directory -s -C $(LIBFT) clean
.PHONY: clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -s -C $(LIBFT) fclean
.PHONY: fclean

re: fclean bonus
.PHONY: re