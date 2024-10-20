NAME            = libftprintf.a
LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a
CC              = gcc
CFLAGS          = -Wall -Werror -Wextra
RM              = rm -f
AR              = ar rcs

SRCS            = ft_printf.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_putunsignednbr_fd.c
OBJS            = $(SRCS:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJS)
				$(MAKE) -C $(LIBFT_PATH)
				ar rcs $(NAME) $(OBJS) $(LIBFT)

clean:
				$(MAKE) clean -C $(LIBFT_PATH)
				$(RM) $(OBJS)

fclean:         clean
				$(MAKE) fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean re bonus
