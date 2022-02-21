# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:51:10 by bperraud          #+#    #+#              #
#    Updated: 2022/02/15 02:39:00 by bperraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### SOURCES FILES ###
SRC			    = main.c
#SRC			    = fractol.c

### PATHS ###
SDIR			= src
HDIR			= include
ODIR			= objs

### OBJECTS ###
OBJ	  			= $(addprefix $(ODIR)/, $(SRC:.c=.o))

### COMPILATION ###
CC				= gcc
#CFLAGS			= -Wall -Wextra -Werror
CFLAGS			= -Wall -Wextra 
LDLIBS			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz 

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
				$(CC) $(OBJ)  $(LDLIBS) -o $(NAME)

#$(NAME):		$(OBJ)
#				$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

### OBJECTS ###
$(ODIR)/%.o: 	$(SDIR)/%.c
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3  -c $< -o $@

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
