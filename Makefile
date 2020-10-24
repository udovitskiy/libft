# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oxylopho <oxylopho@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 23:57:06 by oxylopho          #+#    #+#              #
#    Updated: 2020/10/24 20:36:19 by oxylopho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
OBJ_DIR = bin/
HEADER = libft.h


CHAR = $(addprefix char/,\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_tolower.c\
			ft_toupper.c\
		)

NBR = $(addprefix number/,\
			ft_atoi.c\
			ft_itoa.c\
		)

STR = $(addprefix string/,\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_strclr.c\
			ft_strcpy.c\
			new_empty_str_err.c\
		)

MEM = $(addprefix memory/,\
			ft_bzero.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
		)

MEM_ALLOC = $(addprefix memory_alloc/,\
			ft_calloc.c\
		)

PRINT = $(addprefix print/,\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
		)

LLIST = $(addprefix linked_list/,\
			ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c\
		)

GNL = $(addprefix get_next_line/,\
			get_next_line.c\
		)

SRC = $(CHAR) $(NBR) $(STR) $(MEM) $(MEM_ALLOC) $(PRINT) $(LLIST) $(GNL)
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME)"

$(OBJ): $(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(@)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@mkdir $(addprefix $(OBJ_DIR), char/ number/ string/ memory/ memory_alloc/ print/ linked_list/ get_next_line/)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "All object files have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all
