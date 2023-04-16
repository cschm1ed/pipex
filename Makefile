# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 15:40:52 by cschmied          #+#    #+#              #
#    Updated: 2023/04/14 15:40:56 by cschmied         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH 		:= sources

SOURCES		:= main.c utils.c frees.c wrappers.c

OBJS		:= $(SOURCES:.c=.o)

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror -O2 -g

NAME		:= pipex

LIBFT		:= libft.a

LIBFT_DIR	:= libft

GREEN		:= \033[0;32m
BLUE		:= \033[0;34m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
RESET		:= \033[0m
PURPLE		:= \033[0;35m

$(NAME): $(OBJS)  $(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)Linking...$(RESET)"
	@$(CC) $(CFLAGS) $^ $(LIBFT_DIR)/$(LIBFT) -o $@
	@echo "$(GREEN)Done.$(RESET)"

%.o: %.c
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null 2>&1

.PHONY: clean fclean re all

all: $(NAME)

clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@echo "$(PURPLE)Cleaned.$(RESET)"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
