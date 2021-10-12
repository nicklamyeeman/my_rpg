SRC_DIR		=	./src/

SRC		=	$(SRC_DIR)my_strlen.c		\
			$(SRC_DIR)concatenate.c		\
			$(SRC_DIR)same_strings.c	\
			$(SRC_DIR)get_next_line.c	\
			$(SRC_DIR)create_vector.c	\
			$(SRC_DIR)destroy_map.c		\
			$(SRC_DIR)draw_square.c		\
			$(SRC_DIR)frame_buffer.c	\
			$(SRC_DIR)background_stuff.c	\
			$(SRC_DIR)texture_checker.c	\
			$(SRC_DIR)add_texture.c		\
			$(SRC_DIR)print_buf.c		\
			$(SRC_DIR)delete_from_map.c	\
			$(SRC_DIR)set_spawn.c		\
			$(SRC_DIR)events.c		\
			$(SRC_DIR)load.c		\
			$(SRC_DIR)save.c		\
			$(SRC_DIR)is_command.c		\
			$(SRC_DIR)init_var.c		\
			$(SRC_DIR)main.c

INC		=	-I ./include

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	$(INC) -lc_graph_prog -g3

NAME		=	map_maker

all:			$(OBJ)
			@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
			@rm -f $(OBJ)

fclean:			clean
			@rm -f $(NAME)

re:			fclean all
