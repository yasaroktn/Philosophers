NAME	=	philo
CC		=	gcc
INC		=	philo.h
CFLAGS	=	-Wall -Wextra -Werror -pthread #-fsanitize=thread -g
RM		=	rm -rf

SRCS	=	philo.c			\
			transactions.c	\
			setup.c			\
			thread.c		\
			utils.c			\

OBJS = $(SRCS:.c=.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(R)███████████████████████████
	@echo $(R)███████▀▀▀░░░░░░░▀▀▀███████
	@echo $(R)████▀░░░░░░░░░░░░░░░░░▀████
	@echo $(R)███│░░░░░░░░░░░░░░░░░░░│███
	@echo $(R)██▌│░░░░░░░░░░░░░░░░░░░│▐██
	@echo $(R)██░└┐░░░░░░░░░░░░░░░░░┌┘░██
	@echo $(R)██░░└┐░░░░░░░░░░░░░░░┌┘░░██
	@echo $(R)██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██
	@echo $(R)██▌░│██████▌░░░▐██████│░▐██
	@echo $(R)███░│▐███▀▀░░▄░░▀▀███▌│░███
	@echo $(R)██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██
	@echo $(R)██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██
	@echo $(R)████▄─┘██▌░░░░░░░▐██└─▄████
	@echo $(R)█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████
	@echo $(R)████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████
	@echo $(R)█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████
	@echo $(R)███████▄░░░░░░░░░░░▄███████
	@echo $(R)██████████▄▄▄▄▄▄▄██████████
	@echo $(R)███████████████████████████

%.o: %.c $(INC)
	@echo $(Y)▂▃▄▅▆▇█▓▒░CREAT░▒▓█▇▆▅▄▃▂ [$<]
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM) $(OBJS)
	@echo $(B)▂▃▄▅▆▇█▓▒░CLEAN░▒▓█▇▆▅▄▃▂ [$(OBJS)]

fclean: clean
	@$(RM) $(NAME)
	@echo $(B)▂▃▄▅▆▇█▓▒░CLEAN░▒▓█▇▆▅▄▃▂ [$(NAME)]

re:	fclean all

.PHONY: all, clean, fclean, re