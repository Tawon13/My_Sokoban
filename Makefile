##
## EPITECH PROJECT, 2023
## B-PSU-100-MAR-1-1-sokoban-amine.bechagra
## File description:
## Makefile
##


#SRC =   *.c
SRC =   $(wildcard src/*.c)


OBJ =   $(patsubst %.c, %.o, $(SRC))

NAME =   my_sokoban

all:    $(NAME)

$(NAME): $(OBJ)
		gcc -lncurses -o $(NAME) $(SRC)

clean:
		rm -f $ *.o
		rm -f src/*.o

fclean	:	clean
		rm -f $(NAME)
		rm -f *#
		rm -f src/*.o
		rm -f include/*#
		rm -f *~
		rm -f src/*~
		rm -f include/*~

re: fclean all
