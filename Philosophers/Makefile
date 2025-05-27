# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkulbak <mkulbak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 01:36:07 by mkulbak           #+#    #+#              #
#    Updated: 2025/05/27 16:50:34 by mkulbak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread

SRCS = main.c argv_checker.c utils.c initializer.c free_resources.c error_manage.c simulation.c \
	supervisor.c events.c libft_utils1.c libft_utils2.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJS)
	echo "🔧 Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "✅ $(NAME) Ready!"

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	echo "🧹 Cleaning object files..."
	rm -rf $(OBJDIR)
	echo "✅ Clean complete."

fclean: clean
	echo "🧹 Full cleanup..."
	rm -f $(NAME)
	echo "✅ Full clean complete."

re: fclean all
