NAME			= libftprintf.a
LIBFT			= libft
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f
AR				= ar rcs

SRCS 			=	ft_printf.c
OBJS			=	$(SRCS:.c=.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C ./libft
				cp libft/libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)

clean:			
				$(MAKE) clean -C ./libft
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus