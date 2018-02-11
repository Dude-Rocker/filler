# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 21:48:14 by vgladush          #+#    #+#              #
#    Updated: 2018/02/12 00:18:40 by vgladush         ###   ########.fr        #
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

SRCS	= filler.c ft_fillog.c ft_targcoord.c

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
