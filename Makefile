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

# **************************************************************************** #
#                              Project Information                             #
# **************************************************************************** #
NAME 			= push_swap

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
OBJ_DIR			= obj
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

COMMANDS_DIR = $(SRC_DIR)/commands
CORE_DIR = $(SRC_DIR)/core
ERROR_DIR = $(SRC_DIR)/error_handling
OPERATIONS_DIR = $(SRC_DIR)/operations
SORTING_DIR = $(SRC_DIR)/sorting
UTILS_DIR = $(SRC_DIR)/utils
VALIDATION_DIR = $(SRC_DIR)/validation

# **************************************************************************** #
#                             Source Files                                     #
# **************************************************************************** #
COMMANDS = $(COMMANDS_DIR)/helpers.c \
           $(COMMANDS_DIR)/push.c \
           $(COMMANDS_DIR)/rotate.c \
           $(COMMANDS_DIR)/swap.c \
           $(COMMANDS_DIR)/reverse_rotate.c \
		   $(COMMANDS_DIR)/operations.c \
           $(COMMANDS_DIR)/operations_2.c \
           $(COMMANDS_DIR)/operations_3.c

CORE = $(CORE_DIR)/main.c

ERROR = $(ERROR_DIR)/fatal_error.c \
        $(ERROR_DIR)/handle_error.c

OPERATIONS = $(OPERATIONS_DIR)/append_stack_node.c \
             $(OPERATIONS_DIR)/create_stack_node.c \
             $(OPERATIONS_DIR)/stack_new.c \
             $(OPERATIONS_DIR)/stack_operations.c

PUSH_SWAP = $(PUSH_SWAP_DIR)/lst_utils.c \
            $(PUSH_SWAP_DIR)/lst_utils_2.c

SORTING = $(SORTING_DIR)/sort_small.c \
          $(SORTING_DIR)/sort_three.c \
          $(SORTING_DIR)/sort_big.c

UTILS = $(UTILS_DIR)/free_2d_array.c \
        $(UTILS_DIR)/rotate_and_push.c \
        $(UTILS_DIR)/ft_rotate_type.c \
        $(UTILS_DIR)/helper_sort_big.c \
        $(PUSH_SWAP_DIR)/lst_utils.c \
        $(PUSH_SWAP_DIR)/lst_utils_2.c

VALIDATION = $(VALIDATION_DIR)/has_duplicates.c \
             $(VALIDATION_DIR)/is_number.c \
             $(VALIDATION_DIR)/is_sorted.c \
             $(VALIDATION_DIR)/parse_arguments.c \
             $(VALIDATION_DIR)/parse_strict_atoi.c

SRCS := $(COMMANDS) $(CORE) $(ERROR) $(OPERATIONS) $(PUSH_SWAP) $(SORTING) $(UTILS) $(VALIDATION)

OBJS := $(patsubst $(SRCS)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

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

LIBFT_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIBFT_SRCS))

# **************************************************************************** #
#                              Targets                                         #
# **************************************************************************** #

# All rule: Compile everything
all: $(NAME)

# Build push_swap executable and link with libft
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -I$(INC_DIR) -o $(NAME)

# Rule to rebuild libft.a
$(LIBFT_A): $(LIBFT_MAKEFILE) $(LIBFT_SRCS) $(LIBFT_H)
	$(MAKE) -C $(LIBFT_DIR)

# Pattern rule for compiling object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean object files (including bonus objects)
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full clean including libft.a and push_swap executable
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_A)

# Rebuild everything
re: fclean all

# **************************************************************************** #
#                             Special Rules                                    #
# **************************************************************************** #

# Phony targets
.PHONY: all clean fclean re



#$(COMMANDS_DIR)/helpers.c \#
           #$(COMMANDS_DIR)/push.c \#
           #$(COMMANDS_DIR)/rotate.c \#
           #$(COMMANDS_DIR)/swap.c \#
           #$(COMMANDS_DIR)/reverse_rotate.c#