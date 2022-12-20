# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 14:54:56 by tkong             #+#    #+#              #
#    Updated: 2022/12/10 14:55:44 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = main.c\
	init.c\
	exec.c\
	state.c\
	schedule.c\
	action.c\
	loop.c\
	util.c\
	util2.c\

INC = philo.h

$(NAME): $(SRC) $(INC) Makefile
	cc -Wall -Wextra -Werror -pthread $(SRC) -o $(NAME)

all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
