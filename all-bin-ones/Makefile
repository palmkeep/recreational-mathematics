CC=gcc
CFLAGS=-g -lm -O3 -Wall -Wextra

.PHONY: test, clean
test: all-bin-ones.c
	$(CC) $(CFLAGS) $? -o all-bin-ones
	./all-bin-ones 13

all-bin-ones: all-bin-ones.c
	$(CC) $(CFLAGS) $? -o all-bin-ones

clean:
	rm -f all-bin-ones
