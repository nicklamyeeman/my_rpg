##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Compile everything
##

SRC_DIR		=	./src/

BTL_DIR		=	./battle_mec/

SRC		=	$(SRC_DIR)$(BTL_DIR)put_tried_list.c		\
			$(SRC_DIR)$(BTL_DIR)attack_ennem.c		\
			$(SRC_DIR)$(BTL_DIR)get_classes.c		\
			$(SRC_DIR)$(BTL_DIR)start_fight.c		\
			$(SRC_DIR)$(BTL_DIR)which_perso.c		\
			$(SRC_DIR)$(BTL_DIR)init_spell.c		\
			$(SRC_DIR)$(BTL_DIR)init_spelltxt.c		\
			$(SRC_DIR)$(BTL_DIR)spell_one2.c		\
			$(SRC_DIR)$(BTL_DIR)spell_two2.c		\
			$(SRC_DIR)$(BTL_DIR)init_perso.c		\
			$(SRC_DIR)$(BTL_DIR)cast_spell.c		\
			$(SRC_DIR)$(BTL_DIR)init_combi.c		\
			$(SRC_DIR)$(BTL_DIR)spell_one.c			\
			$(SRC_DIR)$(BTL_DIR)spell_onetxt.c		\
			$(SRC_DIR)$(BTL_DIR)spell_twotxt.c		\
			$(SRC_DIR)$(BTL_DIR)spell_two.c			\
			$(SRC_DIR)$(BTL_DIR)team_turn.c			\
			$(SRC_DIR)$(BTL_DIR)ennemies.c			\
			$(SRC_DIR)$(BTL_DIR)end_turn.c			\
			$(SRC_DIR)$(BTL_DIR)go_fight.c			\
			$(SRC_DIR)$(BTL_DIR)damages.c			\
			$(SRC_DIR)delete_boss.c				\
			$(SRC_DIR)change_gandoulf_dialog.c		\
			$(SRC_DIR)check_button_pressed.c		\
			$(SRC_DIR)items/display_items.c			\
			$(SRC_DIR)items/init_items.c			\
			$(SRC_DIR)destroy_everything.c			\
			$(SRC_DIR)switch_fullscreen.c			\
			$(SRC_DIR)display_window.c			\
			$(SRC_DIR)boss_event.c				\
			$(SRC_DIR)init_persotxt2.c			\
			$(SRC_DIR)house_movement.c			\
			$(SRC_DIR)display_player.c			\
			$(SRC_DIR)string_cutter.c			\
			$(SRC_DIR)reset_buttons.c			\
			$(SRC_DIR)init_combitxt.c			\
			$(SRC_DIR)init_ennemtxt.c			\
			$(SRC_DIR)init_persotxt.c			\
			$(SRC_DIR)battle_event4.c			\
			$(SRC_DIR)battle_event3.c			\
			$(SRC_DIR)battle_event2.c			\
			$(SRC_DIR)is_it_a_fight.c			\
			$(SRC_DIR)display_pause.c			\
			$(SRC_DIR)create_vector.c			\
			$(SRC_DIR)pause_events.c			\
			$(SRC_DIR)display_dead.c			\
			$(SRC_DIR)evenements.c				\
			$(SRC_DIR)display_inv.c				\
			$(SRC_DIR)display_pnj.c				\
			$(SRC_DIR)init_pause.c				\
			$(SRC_DIR)render_mouse.c			\
			$(SRC_DIR)render_stage.c			\
			$(SRC_DIR)same_strings.c			\
			$(SRC_DIR)battle_event.c			\
			$(SRC_DIR)check_select.c			\
			$(SRC_DIR)launch_menu.c				\
			$(SRC_DIR)print_usage.c				\
			$(SRC_DIR)int_to_char.c				\
			$(SRC_DIR)init_battle.c				\
			$(SRC_DIR)concatenate.c				\
			$(SRC_DIR)menu_events.c				\
			$(SRC_DIR)box_creator.c				\
			$(SRC_DIR)transitions.c				\
			$(SRC_DIR)stage_tools.c				\
			$(SRC_DIR)init_window.c				\
			$(SRC_DIR)display_map.c				\
			$(SRC_DIR)move_if_needed.c			\
			$(SRC_DIR)move_player.c				\
			$(SRC_DIR)speak_pnj.c				\
			$(SRC_DIR)load_dialog.c				\
			$(SRC_DIR)game_events.c				\
			$(SRC_DIR)load_pnj.c				\
			$(SRC_DIR)start_game.c				\
			$(SRC_DIR)init_audio.c				\
			$(SRC_DIR)load_scene.c				\
			$(SRC_DIR)foot_steps.c				\
			$(SRC_DIR)add_to_map.c				\
			$(SRC_DIR)init_fight.c				\
			$(SRC_DIR)init_turn5.c				\
			$(SRC_DIR)init_turn4.c				\
			$(SRC_DIR)pause.c				\
			$(SRC_DIR)init_turn3.c				\
			$(SRC_DIR)init_turn2.c				\
			$(SRC_DIR)qsvl_event.c				\
			$(SRC_DIR)qdfv_event.c				\
			$(SRC_DIR)dmva_event.c				\
			$(SRC_DIR)draw_auras.c				\
			$(SRC_DIR)display_f2.c				\
			$(SRC_DIR)display_f3.c				\
			$(SRC_DIR)display_f4.c				\
			$(SRC_DIR)display_f5.c				\
			$(SRC_DIR)display_f.c				\
			$(SRC_DIR)init_turn.c				\
			$(SRC_DIR)more_fct2.c				\
			$(SRC_DIR)new_game.c				\
			$(SRC_DIR)settings.c				\
			$(SRC_DIR)load_map.c				\
			$(SRC_DIR)more_fct.c				\
			$(SRC_DIR)intro.c				\
			$(SRC_DIR)v2f.c					\
			$(SRC_DIR)main.c

LIB		= 	-L ./lib/my -lmy

INC		=	-I ./include -I ./lib/my/include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-g $(INC)

NAME		=	my_rpg

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
