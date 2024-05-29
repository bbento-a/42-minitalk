# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbento-a <bbento-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 10:46:49 by bbento-a          #+#    #+#              #
#    Updated: 2024/05/20 10:26:06 by bbento-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S				= server
NAME_C				= client

# Directories
LIBFT				= ./libft/libft.a
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra #-g
RM					= rm -f

# Source Files
SRC_S		=	$(SRC_DIR)server.c \
				$(SRC_DIR)utils.c
				
SRC_C		=	$(SRC_DIR)client.c \
				$(SRC_DIR)utils.c

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ_S 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_S))
OBJ_C				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_C))

# Build rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME_S) $(NAME_C)

$(NAME_S): 			$(OBJ_S) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o $(NAME_S)
$(NAME_C): 			$(OBJ_C) $(LIBFT)
					$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME_S) $(NAME_C)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re
