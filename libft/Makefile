# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hbrouwer <hbrouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/03 15:06:58 by hbrouwer      #+#    #+#                  #
#    Updated: 2023/03/07 13:21:08 by hbrouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

AR = ar

ARFLAGS = -crs

FLAGS = -Wall -Werror -Wextra

SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		util.c \
		char_functions.c \
		dec_functions.c \
		ft_printf.c \
		hex_functions.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJS = ${SRC:.c=.o}

BONUS_OBJS = ${BONUS_SRC:.c=.o}

all: 		${NAME}

%.o: 		%.c
			@${CC} ${FLAGS} -c $< -o $@

${NAME}: 	${OBJS}
			@${AR} ${ARFLAGS} ${NAME} ${OBJS}	
		
bonus:		${OBJS} ${BONUS_OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} ${BONUS_OBJS}

clean: 
			@rm -f ${OBJS} ${BONUS_OBJS}
	
fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		bonus clean fclean all re