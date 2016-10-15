# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 13:43:27 by palatorr          #+#    #+#              #
#    Updated: 2016/10/12 13:43:29 by palatorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRC		= main.c mandelbrot.c draw.c hooks.c
OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

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

all: obj $(NAME)

full: obj libft libgfx libmlx $(NAME)

obj:
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FTINC) $(GFXINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FTLINK) $(GFXLINK) $(MLXLINK) -o $(NAME)

libft:
	$(LIBFT)

libgfx:
	$(LIBGFX)

libmlx:
	$(LIBMLX)

$(LIBFT):
	make -C ./libft/

$(LIBGFX):
	make -C ./libg/

$(LIBMLX):
	make -C ./minilibx/

clean:
	rm -rf $(OBJDIR)

rclean:
	rm -rf $(OBJDIR)
	make -C ./libft/ clean
	make -C ./libgfx/ clean
	make -C ./minilibx/ clean

fclean: clean
	rm -rf $(NAME)

rfclean: rclean
	rm -rf $(NAME)
	make -C ./libft/ fclean
	make -C ./libgfx/ fclean

re: fclean all

gfx:
	make -C ./libgfx/ re

regfx: gfx fclean all

fullre: rfclean full
