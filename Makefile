FILES = main.c				\
		control.c 			\
		malloc_menagement.c \
		utils.c				\

BFILES = 
		 
NAME = philo
BNAME = bonus/checker
OBJS = ${FILES:.c=.o}
BOBJS = ${BFILES:.c=.o}
FLAGS = -Wall -Wextra -Werror
all : ${NAME}
${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}
bonus : ${BNAME}
${BNAME}: ${BOBJS}
	${CC} ${FLAGS} ${BOBJS} -o ${BNAME}
fclean :
	rm -rf ${OBJS} ${BOBJS} ${NAME} ${BNAME}
clean : 
	rm -rf ${OBJS} ${BOBJS} 
%.o:%.c
	${CC} -c $^ ${FLAGS} -o $@

re : fclean all

git : 
	git add .
	git commit -m "auto commit"
	git push

.PHONY: all re fclean clean