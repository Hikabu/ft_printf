NAME	= libftprintf.a
SRCS =	ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_lowhex.c

HEADER 		= ft_printf.h
OBJ 		= $(SRCS:.c=.o)
FLGS 		= -Wall -Wextra -Werror
CC			= cc
RM			= rm -rf

all: 	$(NAME)

$(NAME): 	$(OBJ) 
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
.PHONY: all clean fclean re