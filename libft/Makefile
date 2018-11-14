# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 01:36:09 by rlucas-d          #+#    #+#              #
#    Updated: 2018/11/01 11:15:11 by rlucas-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = -I./includes/ 
SRC_LIB = ft_isprint.c ft_memset.c ft_strcat.c ft_strlcat.c ft_strsplit.c \
ft_itoa.c ft_putchar.c ft_strchr.c ft_strlen.c ft_strstr.c  ft_strrchr.c \
ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strncat.c ft_strsub.c \
ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strncmp.c ft_strtrim.c \
ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strncpy.c \
ft_tolower.c ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strnequ.c \
ft_toupper.c ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strnew.c \
ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strnstr.c ft_isdigit.c \
ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_striteri.c ft_striter.c \
ft_strmap.c ft_strmapi.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
ft_lstadd.c ft_lstiter.c ft_lstiter.c ft_lstmap.c ft_count_letter.c \
ft_abs.c ft_count.c ft_space.c 
OBJ = $(SRC_LIB:%.c=%.o)

FLAG = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) 
	@ranlib $(NAME)
	@echo "Compilation de la lib"

%.o: %.c
	@gcc -o $@ -c $(FLAGS) $< $(INCLUDES)
	@echo "Compilation de $< en $@"	

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean all
