# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:51:10 by bperraud          #+#    #+#              #
#    Updated: 2022/03/17 17:41:29 by bperraud         ###   ########.fr        #
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
LDLIBS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

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
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3  -c $< -o $@

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
