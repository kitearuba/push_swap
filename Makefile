# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 21:23:07 by chrrodri          #+#    #+#              #
#    Updated: 2024/11/27 17:38:06 by chrrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRC_DIR := src
INC_DIR := include
LIBFT_DIR := libft

# Paths and Dependencies
MAKEFILE = Makefile
HEADER = $(INC_DIR)/push_swap.h $(INC_DIR)/stack.h $(INC_DIR)/utils.h
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/include/libft.h
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
DEPS := $(HEADER) $(MAKEFILE)

# Source Files
SRC := $(SRC_DIR)/core/main.c \
       $(SRC_DIR)/core/push_swap.c \
       $(SRC_DIR)/core/input_validation.c \
       $(SRC_DIR)/core/memory_management.c \
       $(SRC_DIR)/commands/helpers.c \
       $(SRC_DIR)/commands/push.c \
       $(SRC_DIR)/commands/swap.c \
       $(SRC_DIR)/commands/rotate.c \
       $(SRC_DIR)/commands/reverse_rotate.c \
       $(SRC_DIR)/commands/stack_operations.c \
       $(SRC_DIR)/sorting/sort_helper.c \
       $(SRC_DIR)/sorting/find_target_index.c \
       $(SRC_DIR)/sorting/sort_small.c \
       $(SRC_DIR)/sorting/sort_medium.c \
       $(SRC_DIR)/sorting/sort_medium_large.c \
       $(SRC_DIR)/sorting/sort_large.c \
       $(SRC_DIR)/error_handling/error_handle.c \
       $(SRC_DIR)/error_handling/fatal_error.c \
       $(SRC_DIR)/error_handling/clean_all.c \
       $(SRC_DIR)/error_handling/free_on_error.c \
       $(SRC_DIR)/utils/utils.c

# Object Files
OBJ := $(SRC:.c=.o)

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

LIBFT_OBJS := $(LIBFT_SRCS:.c=.o)

# Rules
all: $(NAME)

# Build push_swap executable and link with libft
$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -I$(INC_DIR) -o $(NAME)

# Rule to rebuild libft.a if libft.h or any libft source files change
$(LIBFT_A): $(LIBFT_MAKEFILE) $(LIBFT_SRCS) $(LIBFT_H)
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for compiling object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean object files (including bonus objects)
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean including libft.a and push_swap executable
fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_A)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
