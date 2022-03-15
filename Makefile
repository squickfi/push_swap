MAIN_SRCS = pa_pb.c\
			parse_args.c\
			push_swap.c\
			sort3_4_5.c\
			rr.c\
			rrr.c\
			sort_list.c\
			sort_list2.c\
			sort_list3.c\
			ss.c\
			work_with_lists.c

SRCS = $(addprefix srcs/, $(MAIN_SRCS))

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

include $(wildcard $(DEPS))