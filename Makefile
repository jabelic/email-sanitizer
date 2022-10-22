CFLAGS=-std=c99 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

# 9cc: $(OBJS)
# 		 $(CC) -o 9cc $(OBJS) $(LDFLAGS)
# $(OBJS): 9cc.h

test: 
		./test/test.sh

clean:
		rm -f *.o *~ tmp*

.PHONY: test clean