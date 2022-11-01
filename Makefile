SUFFIX=.c
INCLUDE=include
SRCDIR := src
INCDIR := -I $(wildcard $(SRCDIR)/$(INCLUDE)/*.h)
CFLAGS=-std=c11 -g -O2 -Wall $(INCDIR)
CC = cc
YAHOO := yahoo
SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/$(YAHOO)/*.c)

sanitizer:
		$(CC) $(CFLAGS) $(SRCS)

test: sanitizer
		./test/test.sh

clean:
		rm -f *.o *~ tmp*

.PHONY: test clean
