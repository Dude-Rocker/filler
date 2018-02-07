# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 14:24:08 by vgladush          #+#    #+#              #
#    Updated: 2018/02/07 17:51:19 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= vgladush.filler

GC_FLGS = gcc -Wall -Wextra

SRC_DIR = ./
INC_DIR = ./Includes/ $(LB_PATH)/Includes/
OBJ_DIR = ./obj/
LB_PATH = ./libft/
LB_LINK	= -L ./libft -lft

OBJ		= $(addprefix $(OBJ_DIR),$(OBJS))
INC		= $(addprefix -I, $(INC_DIR))

OBJS	= $(SRCS:.c=.o)

SRCS	= filler.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LB_PATH)
	@gcc -o $(NAME) $(OBJ) $(LB_LINK)
	@echo $(NAME) "ready"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(GC_FLGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LB_PATH) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LB_PATH) fclean
	@rm -f $(NAME)
	@echo $(NAME) "deleted"

re: fclean all
