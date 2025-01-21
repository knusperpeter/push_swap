NAME = push_swap
CC		= cc
AR		= ar
RM		= rm
CFLAGS	= -Wall -Wextra -Werror -g
MAKEFLAGS = -j$(nproc)
HDRS	= include/push_swap.h

PRINTF		= printf
PRINTF_A	= ${PRINTF}/libftprintf.a

SOURCES	=	push_swap.c \
			check_parse.c \
			exit.c \
			rules1.c \
			rules2.c \
			rules3.c \
			sort.c \
			sort_help1.c \
			sort_help2.c

OBJECTS = $(SOURCES:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJECTS) $(HDRS)
	make --no-print-directory all -C $(PRINTF)
	$(CC) $(SOURCES) $(CFLAGS) -o $(NAME) -L. ${PRINTF_A}

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	make --no-print-directory clean -C $(PRINTF)
	$(RM) -rf $(OBJECTS)

fclean	:
	make --no-print-directory fclean -C $(PRINTF)
	$(RM) -rf $(OBJECTS)
	$(RM) -rf $(NAME)

re		: fclean all

# .SILENT:
.PHONY: all clean fclean re
