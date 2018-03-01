##
## Makefile for Makefile in /home/anahor_r/rendu/PSU_2016_malloc/
##
## Made by raphael anahory
## Login   <anahor_r@epitech.eu>
##
## Started on  Wed Jan 25 14:14:08 2017 raphael anahory
## Last update Fri Feb 10 15:58:40 2017 benama_m
##


NAME		=	libmy_malloc.so

SRC		=	malloc.c \
			for_free.c\
			push_list.c\
			function.c\
			remove_list.c\
			thread.c\
			function_2.c\
			realloc.c\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS		=	-W -Wextra -Wall -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -c $(CFLAGS) -fpic $(SRC) -lpthread
		$(CC) -shared -o $(NAME) $(OBJ)

clean:
		rm -rf *.o
		rm -rf *~
		rm -rf \#*

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
