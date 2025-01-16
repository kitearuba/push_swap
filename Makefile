# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 21:23:07 by chrrodri          #+#    #+#              #
#    Updated: 2025/01/14 23:55:00 by chrrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              Project Information                             #
# **************************************************************************** #
NAME 			= push_swap
CHECKER         = checker

# **************************************************************************** #
#                            Compiler and Flags                                #
# **************************************************************************** #
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
RM				= rm -rf
MAKE			= make

# **************************************************************************** #
#                              Directories                                     #
# **************************************************************************** #
SRC_DIR 		= src
INC_DIR 		= include
LIBFT_DIR		= libft

# **************************************************************************** #
#                      File Paths and Dependencies                             #
# **************************************************************************** #
MAKEFILE 		= Makefile
HEADER 			= $(INC_DIR)/push_swap.h $(INC_DIR)/stack.h
LIBFT_A 		= $(LIBFT_DIR)/libft.a
LIBFT_H 		= $(LIBFT_DIR)/$(INC_DIR)/libft.h
LIBFT_MAKEFILE 	= $(LIBFT_DIR)/$(MAKEFILE)
DEPS 			= $(HEADER) $(MAKEFILE)

# **************************************************************************** #
#                               Source File                                    #
# **************************************************************************** #
SRC_COMMON := $(SRC_DIR)/commands/push.c \
               $(SRC_DIR)/commands/reverse_rotate.c \
               $(SRC_DIR)/commands/rotate.c \
               $(SRC_DIR)/commands/swap.c \
               $(SRC_DIR)/error_handling/fatal_error.c \
               $(SRC_DIR)/error_handling/handle_error.c \
               $(SRC_DIR)/sorting/sort_three.c \
               $(SRC_DIR)/sorting/sort_large.c \
               $(SRC_DIR)/sorting/sort_stack.c \
               $(SRC_DIR)/utils/free_2d_array.c \
               $(SRC_DIR)/utils/stack_rotation_operations.c \
               $(SRC_DIR)/utils/find_optimal_rotation.c \
               $(SRC_DIR)/utils/stack_utils.c \
               $(SRC_DIR)/utils/stack_placement_logic.c \
               $(SRC_DIR)/utils/rotation_calculations_ab.c \
               $(SRC_DIR)/utils/rotation_calculations_ba.c \
               $(SRC_DIR)/utils/stack_free.c \
               $(SRC_DIR)/validation/validate.c \
               $(SRC_DIR)/validation/is_sorted.c \
               $(SRC_DIR)/validation/parse_strict_atoi.c

# Source files specific to push_swap
SRC_PUSH_SWAP := $(SRC_DIR)/core/main.c

# Source files specific to checker
SRC_CHECKER := $(SRC_DIR)/checker/checker.c

# Object files
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_CHECKER   = $(SRC_CHECKER:.c=.o) $(SRC_COMMON:.c=.o)

LIBFT_SRCS := $(LIBFT_DIR)/$(SRC_DIR)/ft_isalpha.c $(LIBFT_DIR)/$(SRC_DIR)/ft_isdigit.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_isalnum.c $(LIBFT_DIR)/$(SRC_DIR)/ft_isascii.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_isprint.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strlen.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_memset.c $(LIBFT_DIR)/$(SRC_DIR)/ft_bzero.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_memcpy.c $(LIBFT_DIR)/$(SRC_DIR)/ft_memmove.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strlcpy.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strlcat.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_toupper.c $(LIBFT_DIR)/$(SRC_DIR)/ft_tolower.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strchr.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strrchr.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strncmp.c $(LIBFT_DIR)/$(SRC_DIR)/ft_memchr.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_memcmp.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strnstr.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_atoi.c $(LIBFT_DIR)/$(SRC_DIR)/ft_calloc.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strdup.c $(LIBFT_DIR)/$(SRC_DIR)/ft_substr.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strjoin.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strtrim.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_split.c $(LIBFT_DIR)/$(SRC_DIR)/ft_itoa.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_strmapi.c $(LIBFT_DIR)/$(SRC_DIR)/ft_striteri.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/$(SRC_DIR)/ft_putstr_fd.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/$(SRC_DIR)/ft_putnbr_fd.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_lstnew_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_lstadd_front_bonus.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_lstsize_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_lstlast_bonus.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_lstadd_back_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_lstdelone_bonus.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_lstclear_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_lstiter_bonus.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_lstmap_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_printf.c \
             $(LIBFT_DIR)/$(SRC_DIR)/print_format.c $(LIBFT_DIR)/$(SRC_DIR)/ft_putunbr.c \
             $(LIBFT_DIR)/$(SRC_DIR)/ft_puthex.c $(LIBFT_DIR)/$(SRC_DIR)/handle_char.c \
             $(LIBFT_DIR)/$(SRC_DIR)/handle_string.c $(LIBFT_DIR)/$(SRC_DIR)/handle_pointer.c \
             $(LIBFT_DIR)/$(SRC_DIR)/handle_int.c $(LIBFT_DIR)/$(SRC_DIR)/handle_uint.c \
             $(LIBFT_DIR)/$(SRC_DIR)/handle_hex.c $(LIBFT_DIR)/$(SRC_DIR)/handle_percent.c \
             $(LIBFT_DIR)/$(SRC_DIR)/utils.c $(LIBFT_DIR)/$(SRC_DIR)/get_next_line.c \
             $(LIBFT_DIR)/$(SRC_DIR)/get_next_line_bonus.c $(LIBFT_DIR)/$(SRC_DIR)/ft_strappend.c

LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# **************************************************************************** #
#                              Targets                                         #
# **************************************************************************** #

# All rule: Compile everything
all: $(NAME)

# Build push_swap executable
$(NAME): $(OBJ_PUSH_SWAP) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(LIBFT_A) -I$(INC_DIR) -o $(NAME)

# Bonus rule: Build checker executable
bonus: $(CHECKER)

# Build checker executable
$(CHECKER): $(OBJ_CHECKER) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT_A) -I$(INC_DIR) -o $(CHECKER)

# Rule to rebuild libft.a
$(LIBFT_A): $(LIBFT_MAKEFILE)
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for compiling object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean object files (including bonus objects)
clean:
	rm -f $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean including libft.a, push_swap, and checker executables
fclean: clean
	rm -f $(NAME) $(CHECKER)
	rm -f $(LIBFT_A)

# Rebuild everything
re: fclean all

# **************************************************************************** #
#                             Special Rules                                    #
# **************************************************************************** #

# Phony targets
.PHONY: all bonus clean fclean re