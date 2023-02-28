# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 00:37:21 by geonlee           #+#    #+#              #
#    Updated: 2023/01/27 20:05:04 by geonlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server\
	client

SRCS = server.c\
	 client.c

OBJS	= $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME)	:	$(OBJS)
	cc $(FLAGS) server.o -o server
	cc $(FLAGS) client.o -o client

%.o : %.c
	cc $(FLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re