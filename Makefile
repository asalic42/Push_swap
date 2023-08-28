PATHLIBFT = libft/libft.a
EXEC = push_swap

INCLUDE = libft/libft.h libft/libftprintf/libftprintf.h \
		push_swap.h
CFLAGS = -Wall -Wextra -Werror -g
CC = cc

SRC = push_swap.c create_pila.c errors.c op_swap.c op_rotate.c \
	op_push.c op_reverse.c lst_fct.c utils.c utils_2.c\
	\
	algo_3_2.c algo_until10.c algo_up50.c

OBJ = ${SRC:.c=.o}

.c.o :
	$(CC) $(CFLAGS) -c $<

all : $(PATHLIBFT) $(EXEC) $(INCLUDE)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) -Llibft -lft

$(PATHLIBFT) : 
	make -C libft

clean :
	rm -f $(OBJ)
	make clean -C libft

fclean : clean
	rm -f $(EXEC)
	make fclean -C libft

re : fclean all

.PHONY : all clean fclean re
