# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:51:10 by bperraud          #+#    #+#              #
#    Updated: 2023/08/30 02:32:09 by bperraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### SOURCES FILES ###
SRC			    = main.c fractol.c complex.c window.c move.c zoom.c setup.c

### PATHS ###
SDIR			= src
HDIR			= include
ODIR			= objs

### OBJECTS ###
OBJ	  			= $(addprefix $(ODIR)/, $(SRC:.c=.o))

### COMPILATION ###
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

ifeq ($(shell uname), Linux)
	LDLIBS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else
	LDLIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

RM				= rm -f

### EXECUTABLE ###
NAME			= fractol

all:			tmp $(NAME)

### LINK ###
$(NAME):		$(OBJ)
				$(MAKE) -C ./libft
				$(CC) $(OBJ) $(LDLIBS) libft/libft.a -o $(NAME)

### OBJECTS ###
$(ODIR)/%.o: 	$(SDIR)/%.c
				$(CC) $(CFLAGS) -Imlx  -c $< -o $@

tmp:
				mkdir -p objs

clean:
				$(MAKE) clean -C ./libft
				$(RM) $(OBJ)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
