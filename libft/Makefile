# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalic <asalic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:27:17 by asalic            #+#    #+#              #
#    Updated: 2023/04/13 15:56:02 by asalic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PATHPRINTF = libftprintf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror
COMP = cc $(CFLAGS)

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c \
\
get_next_line.c get_next_line_utils.c get_next_line_bonus.c \
get_next_line_utils_bonus.c

OBJ = ${SRC:.c=.o}

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
			
OBJ_BONUS = ${SRC_BONUS:.c=.o}

.c.o : $(COMP) -Llibftprintf $<
	$(COMP) -c $<

all : $(PATHPRINTF) $(NAME) bonus

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus : $(OBJ_BONUS) 
	ar rcs $(NAME) $(OBJ_BONUS)

$(PATHPRINTF) :
	make -C libftprintf
	cp ./$(PATHPRINTF) ./$(NAME)

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make clean -C libftprintf

fclean : clean
	rm -f $(NAME)
	make fclean -C libftprintf

re : fclean all

.PHONY : all clean fclean re
