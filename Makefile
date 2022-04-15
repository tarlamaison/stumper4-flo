##
## EPITECH PROJECT, 2021
## projectname
## File description:
## Makefile
##

SRC		=	include/steumpeur.c \
			include/parsing.c \
			include/pomekon.c \
			include/display.c \
			include/fight.c

MAIN		= 	include/main.c

OBJ		=	$(SRC:.c=.o)

OBJ_M		=	$(MAIN:.c=.o)

NAME		=	pokemon
INC		=	src/
LIBINC		=	lib/my/src/

TEST		=	unit_tests
TESTS		=	bonus/unit_tests.c

CC		=	gcc
RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Wpedantic
CPPFLAGS	=	-iquote $(INC) -iquote $(LIBINC)
TESTFLAGS	=	--coverage -lcriterion
LDLIBS		=	-lmy
LDFLAGS		=	-L lib/my/
ALLFLAGS	=	$(CPPFLAGS) $(LDLIBS) $(LDFLAGS)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_M)
	make -C lib/my/
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_M)
	$(RM) *.gcda
	$(RM) *.gcno
	make clean -C lib/my/

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST)
	make fclean -C lib/my/

re:	fclean all

tests_run: $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	make -C lib/my/
	$(CC) -o $(TEST) $(OBJ) $(TESTS) $(TESTFLAGS) $(ALLFLAGS)
	./$(TEST)
