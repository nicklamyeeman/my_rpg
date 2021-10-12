##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Compile everything
##

SRC_DIR		=	./bonus/

BTL_DIR		=	./battle_mec/

SRC		=	$(BTL_DIR)battle_orupgrade.c		\
			$(BTL_DIR)put_tried_list.c		\
			$(BTL_DIR)attack_ennem.c		\
			$(BTL_DIR)print_teams.c			\
			$(BTL_DIR)get_classes.c			\
			$(BTL_DIR)choose_hero.c			\
			$(BTL_DIR)start_fight.c			\
			$(BTL_DIR)which_perso.c			\
			$(BTL_DIR)init_spell.c			\
			$(BTL_DIR)spell_one2.c			\
			$(BTL_DIR)spell_two2.c			\
			$(BTL_DIR)init_perso.c			\
			$(BTL_DIR)cast_spell.c			\
			$(BTL_DIR)init_combi.c			\
			$(BTL_DIR)spell_one.c			\
			$(BTL_DIR)spell_two.c			\
			$(BTL_DIR)team_turn.c			\
			$(BTL_DIR)ennemies.c			\
			$(BTL_DIR)end_turn.c			\
			$(BTL_DIR)go_fight.c			\
			$(BTL_DIR)damages.c			\
			main.c

LIB		= 	-L ./lib/my -lmy

INC		=	-I ./include -I ./lib/my/include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-g $(INC)

NAME		=	rpg_simulator

all:			$(OBJ)
			@make -sC ./lib/my
			@gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS) $(INC) -lc_graph_prog

clean:
			@make -sC ./lib/my clean
			@rm -f ./tests/*.gcno
			@rm -f ./tests/*.gcda
			@rm -f ./tests/*.o
			@rm -f ./src/*.gcno
			@rm -f ./src/*.gcda
			@rm -f $(OBJ)

fclean:			clean
			@make -sC ./lib/my fclean
			@rm -f $(NAME)
			@rm -f units-tests

re:			fclean all

tests_run:
			@make -sC ./lib/my
			@make -C ./tests
			./units-tests

.PHONY:			make re clean fclean all
