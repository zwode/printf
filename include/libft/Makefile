# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwode <zwode@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 16:00:15 by bglover           #+#    #+#              #
#    Updated: 2019/09/29 17:09:57 by zwode            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
NAME_C = *.c
NAME_O = $(NAME_C:.c=.o)
RM = /bin/rm -f

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(NAME_C)
	@ar rc $(NAME) $(NAME_O)
	@ranlib $(NAME)

clean:
	@$(RM) $(NAME_O)

fclean:clean
	@$(RM) $(NAME)
	
re: fclean all