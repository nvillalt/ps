# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvillalt <nvillalt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 11:15:22 by nvillalt          #+#    #+#              #
#    Updated: 2023/12/19 13:44:04 by nvillalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#···················#
#		NAME		#
#···················#

NAME = push_swap


#···················#
#		PATH		#
#···················#

OBJ_PATH = obj/

SRC_PATH = src/

INC_PATH = inc/


#···················#
#	   COMPILER		#
#···················#

CC = gcc

CFLAGS = -Wall -Wextra  -g #-Werror

CFLAGS += -I $(INC_PATH) -I $(LIBFT_DIR) -I $(SRC_PATH)


#···················#
#		SRCS		#
#···················#

SRCS = main.c parse_init.c parse_utils.c print_list.c list_utils.c  \
	list_utils_2.c movements_sp.c movements_rr.c sort_algorithm.c sort_three.c \
	sort_more.c sort_utils.c sort_utils_2.c algorithm_movements.c \
	sort_hundred.c

OBJ_NAME = $(SRCS:%.c=%.o)

OBJS = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))


#···················#
#		  RM		#
#···················#

RM = rm -rf

#···················#
#	   LIBFT		#
#···················#

LIBFT_DIR = libft
# search for .a in current directory
LDFLAGS = -L $(LIBFT_DIR)
# lib name
LDLIBS = -lft


#···················#
#		RULES		#
#···················#

.PHONY: all re clean fclean debug

all: $(NAME)

$(NAME): $(OBJS)
	make -sC $(LIBFT_DIR)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS) : | $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
#	make fclean -sC $(LIBFT_DIR)
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
