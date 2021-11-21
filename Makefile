# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: opacaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 09:33:21 by opacaud           #+#    #+#              #
#    Updated: 2021/11/15 09:33:22 by opacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

SAN =		#-fsanitize=thread -g3

LIB =		-pthread

SRC =		main.c check.c init.c create_threads.c \
			launch_actions.c actions.c death.c \
			free.c str_utils.c error.c 

OBJ =		${SRC:.c=.o}

all:		${NAME}

${NAME}:	${OBJ}
			${CC} ${CFLAGS} ${SAN} ${LIB} ${OBJ} -o ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o $@

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY :	all clean fclean re
