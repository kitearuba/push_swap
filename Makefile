# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 21:23:07 by chrrodri          #+#    #+#              #
#    Updated: 2024/11/22 12:00:45 by chrrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR := src
BONUS_SRC_DIR := src_bonus
INC_DIR := include
LIBFT_DIR := libft

# Paths and Dependencies
MAKEFILE = Makefile
HEADER = $(INC_DIR)/push_swap.h
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/include/libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
DEPS := $(HEADER) $(MAKEFILE)

# Source Files
SRC := $(SRC_DIR)/main.c \
       $(SRC_DIR)/push_swap.c \
       $(SRC_DIR)/stack_operations.c \
       $(SRC_DIR)/sort_small.c \
       $(SRC_DIR)/sort_medium.c \
       $(SRC_DIR)/sort_large.c \
       $(SRC_DIR)/input_validation.c \
       $(SRC_DIR)/memory_management.c \
       $(SRC_DIR)/utils.c

# Bonus Source Files
SRC_BONUS := $(BONUS_SRC_DIR)/checker_bonus.c \
             $(BONUS_SRC_DIR)/stack_operations_bonus.c \
             $(BONUS_SRC_DIR)/input_validation_bonus.c

# Object Files
OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

# Rules
all: $(NAME)

# Build push_swap executable and link with libft
$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -I$(INC_DIR) -o $(NAME)

# Rule to rebuild libft.a if libft.h or any libft source files change
$(LIBFT_A): $(LIBFT_MAKEFILE)
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for compiling object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Pattern rule for compiling bonus object files
$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Bonus Rule
bonus: $(OBJ_BONUS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT_A) -I$(INC_DIR) -o $(NAME)_bonus

# Clean object files (including bonus objects)
clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean including libft.a and push_swap executable
fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	rm -f $(LIBFT_A)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
