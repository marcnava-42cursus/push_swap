# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2025/02/10 21:04:56 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	push_swap

CC			=	cc
RM			=	rm -rf

# CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./includes

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
LIBS		=	./libs/libft
INSTR		=	$(SRCSPATH)/instructions
UTILS		=	$(SRCSPATH)/utils
ALGORITHM	=	$(SRCSPATH)/algorithm

# **************************************************************************** #
#		FILES		#

SRCS 		=	$(SRCSPATH)/push_swap.c

SRCS		+=	$(INSTR)/push.c \
				$(INSTR)/rotate.c \
				$(INSTR)/rrotate.c \
				$(INSTR)/swap.c

SRCS		+=	$(UTILS)/error_handler.c \
				$(UTILS)/print_stack.c \
				$(UTILS)/stack_handler.c \
				$(UTILS)/stack_manager.c \
				$(UTILS)/stack_utils.c \
				$(UTILS)/stack.c

SRCS		+=	$(ALGORITHM)/check_tools.c \
				$(ALGORITHM)/init_stacks.c \
				$(ALGORITHM)/sort_three.c \
				$(ALGORITHM)/sort_two.c \
				$(ALGORITHM)/sort.c

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#		RULES		#

all: 			compiling $(NAME)

$(LIBS)/libft.a:
				@$(MAKE) --no-print-directory -C $(LIBS)

$(NAME):		$(OBJS) $(LIBS)/libft.a
				@$(COMPILER) $(INCLUDE) $(OBJS) $(LIBS)/libft.a -o $(NAME)
				@printf "Compiled.\n"

%.o:			%.c
				@$(COMPILER) $(INCLUDE) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

compiling:
				@printf "Compiling...\n"

re:				fclean all

.PHONY:			all clean fclean re compiling
