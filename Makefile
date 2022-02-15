# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 00:51:10 by bperraud          #+#    #+#              #
#    Updated: 2022/02/15 01:11:57 by bperraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### SOURCES FILES ###
SOURCES			= main.c

### PATHS ###
SDIR			= src
HDIR			= include
ODIR			= objs

### OBJECTS ###

#SRC				= $(addprefix $(SDIR)/, $(SOURCES))
OBJ	  			= $(addprefix $(ODIR)/, $(SRC:.c=.o))

### COMPILATION ###
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
#CFLAGS			= -Wall -Wextra -Werror -Imlx -c
LDLIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit

RM				= rm -f

### EXECUTABLE ###
NAME			= fractol

all:			$(NAME)

### LINK ###
$(NAME):		$(OBJ)
				$(MAKE) -C ./libft
				$(CC) $(OBJ) $(LDLIBS) libft/libft.a -o $(NAME)

### OBJECTS ###
#$(ODIR)/%.o: 	$(SDIR)/%.c
$(ODIR)/%.o: 	%.c
				$(CC) $(CFLAGS) $< -o $@


clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
