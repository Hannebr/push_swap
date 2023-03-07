# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/29 21:50:55 by hbrouwer      #+#    #+#                  #
#    Updated: 2023/03/07 11:46:38 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBS = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC = 	lst_add.c push_swap.c operations.c algorithms.c

OBJ = $(SRC:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@cd libft && $(MAKE)
			@$(CC) $^ $(LIBS) -o $(NAME)	
			
%.o: 		%.c 
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

clean: 
			@rm -f $(OBJ)
			@cd libft && $(MAKE) clean
	
fclean:		
			@rm -f $(NAME) $(OBJ)
			@cd libft && $(MAKE) fclean

re:		fclean all