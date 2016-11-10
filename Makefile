# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 13:43:27 by palatorr          #+#    #+#              #
#    Updated: 2016/10/16 17:13:53 by palatorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= main.c mandelbrot.c julia.c draw.c hooks.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3
LINK	= -lpthread

LIBFT	= ./libft/libft.a
FTINC	= -I ./libft/
FTLINK	= -L ./libft/ -lft

LIBGFX	= ./libgfx/libgfx.a
GFXINC	= -I ./libgfx/
GFXLINK	= -L ./libgfx/ -lgfx

LIBMLX	= ./minilibx/libmlx.a
MLXINC	= -I ./minilibx/
MLXLINK	= -L ./minilibx/ -lmlx -framework OpenGL -framework AppKit

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

.PHONY: all full libft libgfx libmlx clean rclean fclean rfclean re fullre

all: obj $(NAME)

full: obj libft libgfx mlx $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(FTINC) $(GFXINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FTLINK) $(GFXLINK) $(MLXLINK) -o $(NAME)

libft: $(LIBFT)

libgfx: $(LIBGFX)

mlx: $(LIBMLX)

$(LIBFT):
	make -C ./libft/

$(LIBGFX):
	make -C ./libgfx/

$(LIBMLX):
	make -C ./minilibx/

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

totalclean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./libgfx clean
	make -C ./minilibx clean

totalfclean: totalclean
	rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./libgfx fclean

re: fclean all

gfx:
	make -C ./libgfx re

regfx: gfx re

fullre: totalfclean libft libgfx mlx all
