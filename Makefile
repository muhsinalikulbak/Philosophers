NAME = philosophers

SRCS =	 philosophers.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

MAKEFLAGS += --silent

all: $(NAME)

$(NAME): $(OBJS)
	echo "✅ Creating $(NAME).."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	echo "✅ $(NAME) Ready!"

clean:
	echo "🧹 Being Cleaned..."
	rm -f $(OBJS)
	echo "✅ Cleaning completed!"

fclean: clean
	echo "🧹 Full cleaning is in progress..."
	rm -f $(NAME)
	echo "✅ Full cleaning completed!"

re: fclean all

.PHONY: all clean fclean re