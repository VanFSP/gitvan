.PHONY:clean
c = gcc
CFLAGS = -Wall -g

%.o:%.c
	$(c) $(CFLAGS) -c $^ -o $@


sources = $(wildcard *.c)
objects = $(patsubst %.c,%.o,$(sources))

main:$(objects)
	$(c) $(objects) -o main

clean:
	rm *.o main
