# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/10 17:01:51 by palatorr          #+#    #+#              #
#    Updated: 2016/10/10 17:01:52 by palatorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= matrix.c matrix_rot.c vertex.c draw_line.c colors.c

NAME		= libgfx.a

FLAGS		= -Wall -Wextra -Werror

SRCS		= $(FILENAMES)
OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

FTINC		= -I ../libft
MLXINC		= -I ../minilibx

.PHONY: all re clean fclean

all: $(NAME)

re: fclean all

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $(NAME)

build/%.o: %.c libgfx.h | build
	@gcc $(FLAGS) $(FTINC) $(MLXINC) -c $< -o $@
