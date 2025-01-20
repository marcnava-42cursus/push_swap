# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2025/01/20 20:09:31 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#		VARIABLES	#

NAME		=	push_swap

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror

COMPILER	=	$(CC) $(CFLAGS) -I

INCLUDE		=	./src/push_swap.h

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
INSTR		=	$(SRCSPATH)/instructions
UTILS		=	$(SRCSPATH)/utils
ALGORITHM	=	$(SRCSPATH)/algorithm
LIBS		=	./libs/libft

# **************************************************************************** #
#		FILES		#

SRCS 		=	$(SRCSPATH)/push_swap.c

SRCS		+=	$(INSTR)/push.c \
				$(INSTR)/rotate.c \
				$(INSTR)/rrotate.c \
				$(INSTR)/swap.c

SRCS		+=	$(UTILS)/stack_handler.c \
				$(UTILS)/stack_manager.c \
				$(UTILS)/stack.c

SRCS		+=	$(ALGORITHM)/init_stacks.c \
				$(ALGORITHM)/sort_three.c \
				$(ALGORITHM)/sort_two.c \
				$(ALGORITHM)/sort.c \
				$(ALGORITHM)/stack_a.c \
				$(ALGORITHM)/stack_b.c

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#		RULES		#

all: 			compiling $(NAME)

$(LIBS)/libft.a:
				@$(MAKE) --no-print-directory -C $(LIBS)

$(NAME):		$(OBJS) $(LIBS)/libft.a
				@$(COMPILER) $(OBJS) $(LIBS)/libft.a -o $(NAME)
				@$(MAKE) --no-print-directory -C $(LIBS) fclean
				@printf "Compiled.\n"

%.o:			%.c
				@$(COMPILER) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

compiling:
				@printf "Compiling program...\n"

re:				fclean all

.PHONY:			all clean fclean re compiling
