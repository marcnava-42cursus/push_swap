# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/26 17:33:23 by marcnava          #+#    #+#              #
#    Updated: 2024/11/25 20:04:47 by marcnava         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *************************************************************************** #
#		COLORS		#

B	=			$(shell tput bold)
BLA =			$(shell tput setaf 0)
RED =			$(shell tput setaf 1)
GRE =			$(shell tput setaf 2)
YEL =			$(shell tput setaf 3)
BLU =			$(shell tput setaf 4)
MAG =			$(shell tput setaf 5)
CYA =			$(shell tput setaf 6)
WHI =			$(shell tput setaf 7)
D	=			$(shell tput sgr0)
BEL =			$(shell tput bel)
CLR =			$(shell tput el 1)

RANDOM_COLOR =	$(shell shuf -e "$(BLA)" "$(RED)" "$(GRE)" "$(YEL)" "$(BLU)" \
				"$(MAG)" "$(CYA)" "$(WHI)" -n 1)

# **************************************************************************** #
#		VARIABLES	#

NAME		=	push_swap

CC			=	cc
RM			=	rm -rf

CFLAGS		=	#-Wall -Wextra -Werror

DFLAGS		=	-g3
DFLAGS		+=	-fsanitize=address

COMPILER	=	$(CC) $(CFLAGS)
LIB			=	ar rcs

MAKEFLAGS	+=	--silent

SHELL		:=	bash

# **************************************************************************** #
#		FOLDERS		#

SRCSPATH	=	./src
LIBSPATH	=	./libs
INSTR		=	$(SRCSPATH)/instructions

# **************************************************************************** #
#		FILES		#

SRCS 		=	$(SRCSPATH)/push_swap.c

SRCS		+=	$(INSTR)/push.c \
				$(INSTR)/rotate.c \
				$(INSTR)/rrotate.c \
				$(INSTR)/swap.c \

OBJS		=	$(SRCS:.c=.o)

# *************************************************************************** #
#		MESSAGES	#

UPDATED		=	$(NAME) up to date! No relink made ( ͡° ͜ʖ ͡°)
COMPILED	=	$(NAME) compiled successfully!
RM_OBJ		=	Removed objects
RM_NAME		=	Removed $(NAME)

# *************************************************************************** #
#		FUNCTIONS	#

define progress_bar
				@total=$(words $(SRCS)); \
				i=0; \
				printf "["; \
				while [[ $$i -lt $$total ]]; do \
					printf " "; \
					((i = i + 1)); \
				done; \
				printf "]\r["; \
				printf "$(GRE)";
endef

define build_libs
				@for lib in $(LIBS); do \
					$(MAKE) -C $(LIBSPATH)/$$lib; \
				done 
endef

ifeq ($(MAKECMDGOALS), debug)
	COMPILER	+=	$(DFLAGS)
endif

# **************************************************************************** #
#		RULES		#

all: 			clearscreen check_up_to_date $(NAME)

$(NAME):		build_libs $(OBJS)
				@$(LIB) $(NAME) $(OBJS)

%.o:			%.c
				$(COMPILER) -I$(HEADERS) -c $< -o $@
				@printf "█"

clean:			clearscreen
				@$(RM) $(OBJS)
				@printf "$(B)$(RANDOM_COLOR)$(RM_OBJ)$(D)\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "$(B)$(RANDOM_COLOR)$(RM_NAME)$(D)\n"

re:				fclean all

.PHONY:			all clean fclean re

# *************************************************************************** #
#		CUSTOM RULES		#

debug:			$(NAME)

check_up_to_date:
				if $(MAKE) --question $(NAME); then \
					printf "$(B)$(RANDOM_COLOR)$(UPDATED)$(D)\n"; \
				else \
					$(MAKE) clearscreen; \
					$(MAKE) launch; \
					$(MAKE) $(NAME); \
					$(MAKE) clearscreen; \
					printf "$(B)$(RANDOM_COLOR)$(COMPILED)$(D)\n"; \
				fi

clearscreen:
				@clear

launch:
				$(call progress_bar)

build_libs:
				$(call build_libs)

.PHONY:			launch clearscreen check_up_to_date