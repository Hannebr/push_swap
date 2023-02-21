# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/29 21:50:55 by hbrouwer      #+#    #+#                  #
#    Updated: 2023/02/21 13:34:32 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

GCC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = 	lst_add.c push_swap.c

OBJS = $(SRC:.c=.o)

all: 		$(NAME)

%.o: 		%.c
			$(CC) $(FLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			$(GCC) -o $(NAME) $(OBJS)	

clean: 
			rm -f $(OBJS)
	
fclean:		clean
			rm -f $(NAME)
