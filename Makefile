# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/29 21:50:55 by hbrouwer      #+#    #+#                  #
#    Updated: 2023/03/16 18:01:19 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC = 	lst_add.c \
		push_swap.c \
		algorithms.c \
		push.c swap.c \
		rotate.c

OBJ = $(SRC:.c=.o)

all: 		$(NAME)

$(NAME): 	$(LIBS) $(OBJ)
			@$(CC) $^ $(LIBS) -o $(NAME)

$(LIBS):	
			@$(MAKE) -C libft all
			
			
%.o: 		%.c 
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean: 
			@rm -f $(OBJ)
			@$(MAKE) -C libft clean
	
fclean:		
			@rm -f $(NAME) $(OBJ)
			@$(MAKE) -C libft fclean

re:			fclean all

.PHONY:		all clean fclean re