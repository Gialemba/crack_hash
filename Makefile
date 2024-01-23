# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tali <tali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 21:52:51 by tali              #+#    #+#              #
#    Updated: 2024/01/23 23:33:43 by tali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Werror -Wextra -g
CC		= gcc

PATHS	= src/
PATHO	= obj/

LIB		= libft/libft.a
INC		= -I ./inc

NAME	= cracking

SRC		= $(notdir $(wildcard ${PATHS}*.c))
SRCS	= ${addprefix ${PATHS}, ${SRC}}
OBJ		= ${SRC:.c=.o}
OBJS	= ${addprefix ${PATHO}, ${OBJ}}

${PATHO}%.o: ${PATHS}%.c ${PATHO}
	${CC} ${CFLAGS} -c $< -o $@ ${INC}

all: ${NAME}

${PATHO}:
	mkdir ${PATHO}

${LIB}:
	make -C libft/

${NAME}: ${LIB} ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${INC}

clean:
	rm -rf ${OBJS} ${PATHO} 
	make clean -C libft/

fclean: clean
	rm -rf ${NAME}
	make fclean -C libft/

re:  fclean all

.PHONY : clean all fclean re
