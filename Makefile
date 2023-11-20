# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kupferstrahl <kupferstrahl@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 22:37:03 by kupferstrah       #+#    #+#              #
#    Updated: 2023/10/03 12:28:35 by kupferstrah      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

CFILES = src/main.c src/utils/init.c src/utils/utils.c \
			src/utils/threads.c	src/utils/actions.c \
			
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	
$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
clean:
	@rm -f $(OBJECTS)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

norm:
	norminette ft_printf utils checker

.PHONY: all clean fclean re norm