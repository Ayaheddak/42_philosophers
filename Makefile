# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 14:46:54 by aheddak           #+#    #+#              #
#    Updated: 2022/08/27 16:31:37 by aheddak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

UTILS	=	time.c parsing.c philosophers.c routine.c

FLAGS	=	-Wall -Wextra -Werror -fsanitize=thread -g -pthread

OBJCT	=	${UTILS:.c=.o}

RM		=	rm -f

CC		=	gcc

all		:	$(NAME)

$(NAME)	:	$(OBJCT)	
	$(CC) $(FLAGS) $(UTILS) -o $(NAME)

clean :
	${RM} $(OBJCT)

fclean : clean
	${RM} ${NAME}

re : fclean all