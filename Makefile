# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/15 22:21:10 by framel            #+#    #+#              #
#    Updated: 2016/12/06 22:00:29 by framel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

IFLAG = -I.

LIB = ./libft/libft.a

CFLAGS = -Wall -Wextra -Werror

HEADER = lem_in.h

SRCS = main error tube room name cmd swap graph path

SRCS := $(addsuffix .c, $(SRCS))

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(HEADER) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIB)
	@echo "$(NAME) is done"

$(LIB):
	make -C ./libft

%o: %.c
	@$(CC) -o $@ $(CFLAGS) -c $? $(IFLAG)
	@echo "creating $@ from $?"

clean:
	@/bin/rm -f $(OBJS)
	@make -C ./libft clean
	@echo "cleaning $(NAME) objects files"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@echo "cleaning all $(NAME) files"

re: fclean all
	@echo "$(NAME) is reset"

.PHONY: all clean fclean re
