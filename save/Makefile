# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:51:10 by bperraud          #+#    #+#              #
#    Updated: 2022/03/15 21:30:26 by bperraud         ###   ########.fr        #
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
LDLIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

### EXECUTABLE ###
NAME			= fractol

all:			$(NAME)

### LINK ###
#$(NAME):		$(OBJ)
#				$(MAKE) -C ./libft
#				$(CC) $(OBJ) $(DFLAGS) libft/libft.a -o $(NAME)
#				$(CC) $(OBJ) $(LDLIBS) libft/libft.a -o $(NAME)

$(NAME):		$(OBJ)
				$(MAKE) -C ./libft
				$(CC) $(OBJ) $(CFLAGS) -L libmlx -lmlx -o $(NAME)

#$(NAME):		$(OBJ)
#				$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

### OBJECTS ###
$(ODIR)/%.o: 	$(SDIR)/%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
