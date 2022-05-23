# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 18:06:09 by shaas             #+#    #+#              #
#    Updated: 2022/05/23 19:05:52 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror -g -pthread
DIR_HEADERS =	includes/
DIR_SRC		=	src/
DIR_OBJ		=	obj/
SRC			=	src/philo.c src/parser.c src/utils.c src/error_check.c \
				src/threads.c src/get_curr_time.c
OBJ			=	$(SRC:$(DIR_SRC)%.c=$(DIR_OBJ)%.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(CC) $(CC_FLAGS) $(SRC) -o $(NAME)
				@printf $(CYAN)"$(NAME) created\n"$(RESET)

$(DIR_OBJ)%.o:	$(DIR_SRC)%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CC_FLAGS) $(CPPFLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@printf "$(notdir $<) compiled\n"

clean:
				@rm -rf $(DIR_OBJ)
				@printf $(RED)"Object files removed\n"$(RESET)
				
fclean:			clean
				@rm -rf $(NAME)
				@printf $(RED)"$(NAME) removed\n"$(RESET)

re:				fclean all

exec:
				./$(NAME)

both:			$(NAME) exec

.PHONY:			all clean fclean re

#text modifiers#
RED =				"\e[31m"
GREEN =				"\e[32m"
YELLOW =			"\e[33m"
BLUE =				"\e[34m"
MAGENTA =			"\e[35m"
CYAN =				"\e[36m"
LIGHTGRAY =			"\e[37m"
DARKGRAY =			"\e[90m"
LIGHTRED =			"\e[91m"
LIGHTGREEN =		"\e[92m"
LIGHTYELLOW =		"\e[93m"
LIGHTBLUE =			"\e[94m"
LIGHTMAGENTA =		"\e[95m"
LIGHTCYAN =			"\e[96m"
RED_BG =			"\e[41m"
GREEN_BG =			"\e[42m"
YELLOW_BG =			"\e[43m"
BLUE_BG =			"\e[44m"
MAGENTA_BG =		"\e[45m"
CYAN_BG =			"\e[46m"
LIGHTGRAY_BG =		"\e[47m"
DARKGRAY_BG =		"\e[100m"
LIGHTRED_BG =		"\e[101m"
LIGHTGREEN_BG =		"\e[102m"
LIGHTYELLOW_BG =	"\e[103m"
LIGHTBLUE_BG =		"\e[104m"
LIGHTMAGENTA_BG =	"\e[105m"
LIGHTCYAN_BG =		"\e[106m"
BOLD =				"\e[1m"
ITALIC =			"\e[3m"
UNDERLINED =		"\e[4m"
RESET =				"\e[0m"
