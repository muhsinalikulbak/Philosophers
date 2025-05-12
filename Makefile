# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 01:36:07 by mkulbak           #+#    #+#              #
#    Updated: 2025/05/13 00:14:15 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

SRC_DIR = Philosophers
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(SRC_DIR)/philosophers.c \
       $(SRC_DIR)/argv_checker.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/initializer.c \
       $(SRC_DIR)/clear_resources.c \
       $(SRC_DIR)/error_manage.c \


OBJS = $(SRCS:.c=.o)

INCLUDE = -I$(SRC_DIR) -I$(LIBFT_DIR)

MAKEFLAGS += --silent

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	echo "🔧 Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "✅ $(NAME) Ready!"

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	echo "🔨 Compiling $<..."
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	echo "🔷 Compiling LIBFT..."
	make -C $(LIBFT_DIR) --no-print-directory
	echo "✅ LIBFT Ready!"

clean:
	echo "🧹 Cleaning object files..."
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean --no-print-directory
	echo "✅ Clean complete."

fclean: clean
	echo "🧹 Full cleanup..."
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean --no-print-directory
	echo "✅ Full clean complete."

re: fclean all

.PHONY: all clean fclean re
