NAME   :=	libftprintf.a

SRCS   :=	ft_printf.c ft_cleaner.c ft_ctoa.c ft_distributor.c \
			ft_exception.c ft_arg_fill.c ft_itoa.c ft_print_arg.c \
			ft_ptoa.c ft_putchar.c ft_release_c.c ft_release_di.c \
			ft_release_p.c ft_release_s.c ft_release_u.c ft_release_x.c \
			ft_release_xx.c ft_release.c ft_strcmp.c ft_substr.c \
			ft_strlen.c ft_utoa.c ft_xtoa.c ft_xxtoa.c ft_release_percent.c

OBJS   :=	$(SRCS:.c=.o)

HDR    :=	ft_printf.h

CC     :=	gcc

CFLAGS :=	-Wall -Wextra -Werror -MMD 

all:		$(NAME)

$(NAME):	$(OBJS) $(HDR)
			ar -crs $(NAME) $?

bonus:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c $<

include		$(wildcard *.d)

clean:
			rm -rf *.o *.d

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
