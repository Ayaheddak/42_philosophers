# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aheddak <aheddak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/17 14:46:54 by aheddak           #+#    #+#              #
#    Updated: 2022/08/07 02:43:33 by aheddak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phhilosophers

BONUS	=	
 
UTILS	=	phhilosophers.c

UTILS_BONUS	= 

FLAGS	=	-Wall -Wextra -Werror

OBJCT	=	${UTILS:.c=.o}

OBJCTB	=	${UTILS_BONUS:.c=.o}

RM		=	rm -f

CC		=	gcc

all		:	$(NAME)

$(NAME)	:	$(OBJCT)	
	$(CC) $(FLAGS) $(UTILS) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(OBJCTB)
	$(CC) $(FLAGS) $(UTILS_BONUS) -o $(BONUS)

clean :
	${RM} $(OBJCT) $(OBJCTB)

fclean : clean
	${RM} ${NAME} ${BONUS}

re : fclean all