# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2025/03/17 13:45:52 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	push_swap

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./includes

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
BUILD		=	./build
ANIMATION	=	./animation

LIBFT		=	./libs/libft
INSTR		=	$(SRCSPATH)/instructions
UTILS		=	$(SRCSPATH)/utils
ALGORITHM	=	$(SRCSPATH)/algorithm

# **************************************************************************** #
#		FILES		#

FRAMES 		= 	$(ANIMATION)/f1.c \
				$(ANIMATION)/f2.c \
				$(ANIMATION)/f3.c \
				$(ANIMATION)/f4.c \
				$(ANIMATION)/f5.c \
				$(ANIMATION)/f6.c \
				$(ANIMATION)/f7.c \
				$(ANIMATION)/f8.c \
				$(ANIMATION)/f9.c

SRCS 		=	$(SRCSPATH)/push_swap.c

SRCS		+=	$(INSTR)/push.c \
				$(INSTR)/rotate.c \
				$(INSTR)/rrotate.c \
				$(INSTR)/swap.c

SRCS		+=	$(UTILS)/error_handler.c \
				$(UTILS)/print_stack.c \
				$(UTILS)/ps_split.c \
				$(UTILS)/stack_handler.c \
				$(UTILS)/stack_manager.c \
				$(UTILS)/stack_utils.c \
				$(UTILS)/stack_utils2.c \
				$(UTILS)/stack.c

SRCS		+=	$(ALGORITHM)/check_tools.c \
				$(ALGORITHM)/sort_three.c \
				$(ALGORITHM)/sort_two.c \
				$(ALGORITHM)/sort.c

OBJS		=	$(SRCS:$(SRCSPATH)/%.c=$(BUILD)/%.o)

# **************************************************************************** #
#		RULES		#

run: 
	# @make -s animate &
	@$(MAKE) -s all
	@wait $$!
.PHONY: run

all: $(LIBFT)/libft.a $(NAME)
.PHONY: all

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

fclean:	clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -s -C $(LIBFT) fclean
.PHONY: fclean

re:	fclean run
.PHONY: re

animate:
	@for frame in $(FRAMES); do \
		clear; \
		sed '1,13d; $$d' $$frame; \
		sleep 0.4; \
	done
.PHONY: animate