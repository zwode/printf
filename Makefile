# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwode <zwode@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/20 16:00:15 by bglover           #+#    #+#              #
#    Updated: 2019/09/26 19:05:21 by zwode            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a
NAME_C = ft_printf.c flags_2.c flags.c ft_print_float.c

DIR_S = srcs
DIR_O = outF

SRCS = $(addprefix $(DIR_S)/,$(NAME_C))
OBJS = $(addprefix $(DIR_O)/,$(NAME_C:%.c=%.o))

TEST = srcs/test.c

FLAGS = #-Wall -Wextra -Werror

CP = include/libft/libft.a

LIBFT = -C include/libft/

INCLUDES = include

all:$(NAME)

$(NAME): $(OBJS)
	@make $(LIBFT)
	@cp $(CP) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf '\033[32m[ ✔ ]done! %s\n'

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p outF
	@$(CC) $(FLAGS) -I $(INCLUDES) -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean $(LIBFT)
	@rm -rf a.out
	@printf '\033[32m[ ✔ ]clean! %s\n'

fclean:clean
	@rm -rf $(NAME)
	@make fclean $(LIBFT)

re: fclean all
	@printf '\033[32m[ ✔ ]re! %s\n'

norm:
	@norminette $(DIR_S)/*.c include/*.c

gcc: clean
	@gcc $(TEST) $(NAME)
	@printf '\033[32m[ ✔ ]compile! %s\n\033[37m'
	@./a.out
