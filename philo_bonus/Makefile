# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 18:46:30 by mkulbak           #+#    #+#              #
#    Updated: 2025/06/13 13:11:37 by muhsin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAGS = -pthread 

SRCS = main.c argv_checker.c utils.c   error_manage.c initializer.c\
	  libft_utils1.c libft_utils2.c free_resources.c events.c simulation.c\
	  simulation_helper.c

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
