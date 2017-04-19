# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 14:05:39 by framel            #+#    #+#              #
#    Updated: 2016/12/06 14:28:20 by framel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

IFLAG = -I.

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRCS = strlen putchar putchar_fd putnbr putstr\
	  strstr strcpy strdup strncpy isdigit\
	  memset bzero strcat memcpy memccpy\
	  isalnum isalpha isascii isprint tolower\
	  toupper atoi memmove memchr memcmp\
	  strncat strlcat strchr strrchr strnstr\
	  strcmp strncmp memalloc memdel strnew\
	  strdel strclr striter striteri strmap\
	  strmapi strequ strnequ strsub strjoin\
	  strtrim strsplit itoa putendl putstr_fd\
	  putendl_fd putnbr_fd lstnew lstdelone lstdel\
	  lstadd lstiter lstmap max3 nbrlen putstr_ret\
	  strndup addchar anbcstr countchar nbrlen_base\
	  buffalloc buffrealloc strbuff strbuffend gnl\
	  lstfifo lstlifo strnjoin stabuff itabuff\
	  isstrsizet atosizet isintab error

SRCS := $(addprefix ft_, $(SRCS))

SRCS := $(addsuffix .c, $(SRCS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) is done"

%.o: %.c
	@$(CC) $(CFLAGS) -c $? $(IFLAG)
	@echo $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "cleaning all $(NAME) files"

re: fclean all
	@echo "$(NAME) is reset"

.PHONY: all clean fclean re
