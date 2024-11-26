# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2024/11/26 22:09:06 by marcnava         ###   ########.fr        #
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
LIBS		=	./libs/libft

# **************************************************************************** #
#		FILES		#

SRCS 		=	$(SRCSPATH)/push_swap.c

SRCS		+=	$(INSTR)/push.c \
				$(INSTR)/rotate.c \
				$(INSTR)/rrotate.c \
				$(INSTR)/swap.c

OBJS		=	$(SRCS:.c=.o)

# **************************************************************************** #
#		RULES		#

all: 			compiling $(NAME)

$(LIBS)/libft.a:
				@$(MAKE) --no-print-directory -C $(LIBS)

$(NAME):		$(OBJS) $(LIBS)/libft.a
				@$(COMPILER) $(INCLUDE) $(OBJS) $(LIBS)/libft.a -o $(NAME)
				@$(MAKE) --no-print-directory -C $(LIBS) fclean
				@printf "Compiled.\n"

%.o:			%.c
				@$(COMPILER) $(INCLUDE) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

compiling:
				@printf "Compiling program...\n"

re:				fclean all

.PHONY:			all clean fclean re compiling
