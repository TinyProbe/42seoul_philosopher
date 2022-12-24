# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 05:37:06 by tkong             #+#    #+#              #
#    Updated: 2022/12/21 05:37:11 by tkong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
SRC = main_bonus.c\
	init_bonus.c\
	exec_bonus.c\
	schedule_bonus.c\
	think_bonus.c\
	eat_bonus.c\
	sleep_bonus.c\
	loop_bonus.c\
	util_bonus.c\
	util2_bonus.c\

INC = philo_bonus.h

$(NAME): $(SRC) $(INC) Makefile
	cc -Wall -Wextra -Werror $(SRC) -o $(NAME)

all: $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
