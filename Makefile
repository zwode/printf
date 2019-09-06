# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwode <zwode@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 16:00:15 by bglover           #+#    #+#              #
#    Updated: 2019/09/06 20:54:51 by zwode            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_C = srcs/ft_printf.c srcs/flags.c
#NAME_O = ft_printf.o flags.o

SRCS = $(addprefix srcs/,$(NAME_C))
OBJS = $(addprefix musor/,$(NAME_C:.c=.o))

TEST = srcs/test.c

FLAGS = -Wall -Wextra -Werror -02

CP = ./include/libft/libft.a

LIBFT = -C include/libft/

INCLUDES = include

all: $(NAME)
$(NAME): $(NAME_O)

	@make $(LIBFT)
	@cp $(CP) ./$(NAME)
	@gcc -c $(NAME_C)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
#	gcc $(TEST) $(NAME)

	@mkdir -p musor
	musor/%.o: srcs/%.c
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<
clean:
	rm -rf $(NAME_O)
	make fclean $(LIBFT)

fclean:clean
	rm -rf $(NAME)

re: fclean all