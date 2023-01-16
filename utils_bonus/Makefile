SRCS	=	*.c
OBJS	=	$(SRCS:.c=.o)
FLAGS	=	-Werror -Wall -Wextra

all: $(SRCS)
	gcc -c $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)
