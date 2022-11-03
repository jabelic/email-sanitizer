SUFFIX=.c
INCLUDE=include
SRCDIR := src
INCDIR := -I $(wildcard $(SRCDIR)/$(INCLUDE))
CFLAGS=-std=c11 -g -O2 -Wall $(INCDIR)
CC = cc
YAHOO := yahoo
YHOG := yahoo/general
# YHON := yahoo/new
SRCS := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/$(YAHOO)/*.c) $(wildcard $(SRCDIR)/$(YHOG)/*.c)

sanitizer:
		$(CC) $(CFLAGS) $(SRCS)

test: sanitizer
		./test/test.sh

clean:
		rm -f */*.o

.PHONY: test clean
