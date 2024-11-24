# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 19:09:02 by marcnava          #+#    #+#              #
#    Updated: 2024/11/11 19:11:45 by marcnava         #+#    #+#              #
#                                                                              #
# **************************************************************************** #

# *************************************************************************** #
#		VARIABLES		#

NAME		=	push_swap

CC			=	cc
RM			=	rm -rf

CFLAGS		=	-Wall -Wextra -Werror
# Enable debug mode level 3 and address sanitizer for memory leaks
DFLAGS		=	-g3
DFLAGS		+=	-fsanitize=address

LIB			=	ar rcs

# Silent mode, doesn't print log messages
MAKEFLAGS	+=	--silent

# Change the shell to bash
SHELL		:=	bash

# Libraries
LIBS		=

# Paths
OBJSPATH	=	./build/
SRCSPATH	=	./src/
LIBSPATH	=	./libs/

# *************************************************************************** #
#		COLORS			#

B			=	$(shell tput bold)
BLA			=	$(shell tput setaf 0)
RED			=	$(shell tput setaf 1)
GRE			=	$(shell tput setaf 2)
YEL			=	$(shell tput setaf 3)
BLU			=	$(shell tput setaf 4)
MAG			=	$(shell tput setaf 5)
CYA			=	$(shell tput setaf 6)
WHI			=	$(shell tput setaf 7)
D			=	$(shell tput sgr0)
BEL			=	$(shell tput bel)
CLR			=	$(shell tput el 1)

# *************************************************************************** #
#		MESSAGES		#

UPDATED		=	$(NAME) up to date! No relink made ( ͡° ͜ʖ ͡°)
UPDATED_B	=	bonus up to date! No relink made ( ͡° ͜ʖ ͡°)
COMPILED	=	$(NAME) compiled successfully!
COMPILED_B	=	bonus compiled successfully!
RM_OBJ		=	Removed $(OBJSPATH)
RM_NAME		=	Removed $(NAME)

# *************************************************************************** #
#		FILES			#

SRCS		=
SRCS_B		=

OBJS		=	$(SRCS:$(SRCSPATH)%.c=$(OBJSPATH)%.o)
OBJS_B		=	$(SRCS_B:$(SRCSPATH)%.c=$(OBJSPATH)%.o)

# *************************************************************************** #
#		FUNCTIONS		#

define progress_bar
				@total=$(words $(SRCS)); \
				i=0; \
				printf "["; \
				while [[ $$i -lt $$total ]]; do \
					printf "  "; \
					((i = i + 1)); \
				done; \
				printf "]\r["; \
				printf "$(GRE)";
endef

define progress_bar_bonus
				@total=$(words $(SRCS_B)); \
				i=0; \
				printf "["; \
				while [[ $$i -lt $$total ]]; do \
					printf " "; \
					((i = i + 1)); \
				done; \
				printf "]\r["; \
				printf "$(YEL)";
endef

# *************************************************************************** #
#		RULES			#

all:			clearscreen check_up_to_date $(NAME)

$(NAME):		$(OBJS) $(LIBS)
				@$(LIB) $(NAME) $(OBJS)
				@echo "Building $(NAME)..."
				@$(CC) -o $(NAME) $(OBJS) $(DFLAGS)

bonus:          clearscreen check_up_to_date_bonus

$(BONUS_NAME):	$(OBJS_B) $(LIBS)
				@$(LIB) $(BONUS_NAME) $(OBJS_B)
				@echo "Building $(BONUS_NAME)..."
				@$(CC) -o $(BONUS_NAME) $(OBJS_B) $(DFLAGS)

# Compile libraries
$(LIBS):
				$(foreach lib,$(LIBS),$(eval $(lib)_MAKE := $(shell make -C $(LIBSPATH)$(lib))))

clean:			clearscreen
				@$(RM) $(OBJSPATH)
				$(RM) .bonus
				$(MAKE) print_title
				@printf "$(B)$(RANDOM_COLOR)$(RM_OBJ)$(D)\n"
				$(foreach lib,$(LIBS),make -C $(LIBSPATH)$(lib) clean;)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(BONUS_NAME)
				@printf "$(B)$(RANDOM_COLOR)$(RM_NAME)$(D)\n"

re:				fclean all

.bonus:			launch_bonus $(OBJS_B)
				@$(LIB) $(BONUS_NAME) $(OBJS_B)
				@touch .bonus
				@printf "\n$(B)$(RANDOM_COLOR)$(COMPILED_B)$(D)\n"

.PHONY:			all clean fclean re bonus $(LIBS)

# *************************************************************************** #
#       CUSTOM RULES        #

check_up_to_date:
				if $(MAKE) --question $(NAME); then \
					$(MAKE) print_title; \
					printf "$(B)$(RANDOM_COLOR)$(UPDATED)$(D)\n"; \
				else \
					$(MAKE) clearscreen; \
					$(MAKE) launch; \
					$(MAKE) $(NAME); \
					$(MAKE) clearscreen; \
					$(MAKE) print_title; \
					printf "$(B)$(RANDOM_COLOR)$(COMPILED)$(D)\n"; \
				fi

check_up_to_date_bonus:
				if [ -f .bonus ]; then \
					$(MAKE) print_title; \
					printf "$(B)$(RANDOM_COLOR)$(UPDATED_B)$(D)\n"; \
				else \
					$(MAKE) clearscreen; \
					$(MAKE) launch_bonus; \
					$(MAKE) .bonus; \
					$(MAKE) clearscreen; \
					$(MAKE) print_title; \
					printf "$(B)$(RANDOM_COLOR)$(COMPILED_B)$(D)\n"; \
				fi

$(OBJSPATH):
				@mkdir -p $(dir $@) # 2> /dev/null || true

clearscreen:
				@clear

print_title:
				@printf "%s\n" \
				"$(B)$(GRE)" \
				" __    __    ______    __  __    ______    ______   __    __        ______    " \
				"/\ \"-./  \  /\  __ \  /\ \/ /   /\  ___\  /\  ___\ /\ \  /\ \      /\  ___\  " \
				"\ \ \-./\ \ \ \  __ \ \ \  _\"-. \ \  __\  \ \  __\ \ \ \ \ \ \____ \ \  __\  " \
				" \ \_\ \ \_\ \ \_\ \_\ \ \_\ \_\ \ \_____\ \ \_\    \ \_\ \ \_____\ \ \_____\ " \
				"  \/_/  \/_/  \/_/\/_/  \/_/\/_/  \/_____/  \/_/     \/_/  \/_____/  \/_____/ " \
				"$(D)"

launch:
				$(MAKE) print_title
				$(call progress_bar)

launch_bonus:
				$(MAKE) print_title
				$(call progress_bar_bonus)

.PHONY:			launch launch_bonus clearscreen check_up_to_date check_up_to_date_bonus
