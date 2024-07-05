# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbiteau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 13:55:38 by cbiteau           #+#    #+#              #
#    Updated: 2024/07/04 14:47:43 by cbiteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = Cub3D
CC      = clang
CFLAGS  = -Wall -Werror -Wextra -g -Iincludes -Iminilibx-linux
LIBFT   = libft/libft.a
AUTHOR  = Céline & Clément - The FPS Masters
DATE    = 04/07/2024

SRCS        =                 initialize/init_image.c \
                        initialize/init_map_info.c \
                        initialize/init_player_in_field.c \
                        initialize/init_player.c \
                        initialize/init_raycast.c \
                        initialize/init.c \
                        initialize/init_mlx.c \
                        parsing/parser_input.c \
                        parsing/parser_map_build.c \
                        parsing/parser_map_elements.c \
                        utils/utils.c \
                        movement/check_move.c \
                        movement/moving.c \
                        movement/user_input.c \
                        exiting/free.c \
                        exiting/quit_the_game.c \
						minimap/minimap.c \
						raycaster/raycaster.c \


MAIN        = main.c

OBJ_MAIN    = $(addprefix objs/, ${MAIN:.c=.o})
OBJS        = $(addprefix objs/, ${SRCS:.c=.o})
OBJS_TESTS  = $(addprefix objs_tests/, ${SRCS_TESTS:.c=.o})

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[KO]"
WARN_STRING  = "[WARN]"
COM_STRING   = "Compiling"

define run
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
if [ $$RESULT -ne 0 ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
elif [ -s $@.log ]; then \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
else  \
  printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
fi; \
cat $@.log; \
rm -f $@.log; \
exit $$RESULT
endef

all:    header $(NAME)

header:
	@printf "%b" "$(OK_COLOR)"
	@echo "   ____  _    _ ____  ____  _____ "
	@echo "  / ___|| |  | |  _ \ ___ |  __ \\"
	@echo " | |    | |  | | | | \___ \| |  | |"
	@echo " | |___ | |__| | |_| |___) | |__| |"
	@echo "  \____| \____/|____/|____/|____/ "
	@echo
	@printf "%b" "$(OBJ_COLOR)Name:   $(WARN_COLOR)$(NAME)\n"
	@printf "%b" "$(OBJ_COLOR)Author: $(WARN_COLOR)$(AUTHOR)\n"
	@printf "%b" "$(OBJ_COLOR)Date:   $(WARN_COLOR)$(DATE)\n\033[m"
	@echo

$(NAME):    $(LIBFT) ${OBJS} ${OBJ_MAIN}
	@$(call run,$(CC) $(CFLAGS) -o $@ ${OBJS} ${OBJ_MAIN} -L./libft -lft -lreadline -lncurses)

objs/%.o:  srcs/%.c
	@mkdir -p $(dir $@)
	@$(call run,$(CC) $(CFLAGS) -c $< -o $@)

$(LIBFT):
	@$(call run,make -sC ./libft libft.a)

clean:      header
	@rm -rf objs
	@make -sC ./libft clean
	@printf "%-53b%b" "$(COM_COLOR)clean:" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"

fclean:     header clean
	@rm -rf $(NAME)
	@make -sC ./libft fclean
	@printf "%-53b%b" "$(COM_COLOR)fclean:" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"

re:         fclean all

.PHONY:     all clean fclean re libft header
