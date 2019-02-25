CC:= $(CROSS_COMPILE)gcc
CFLAGS:= -g
LDFLAGS:= -g -lm 

all: test

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

test: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -f *.o
	rm -f test
