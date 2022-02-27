EXE=executable
CC=clang++
CFLAGS=-O2 -std=c++20 -Wall -Wextra

.PHONY: test, clean
test: $(EXE) main.cpp
	cat test.in | ./$(EXE)

$(EXE): main.cpp
	$(CC) $(CFLAGS) -o $(EXE) main.cpp

clean:
	rm -rf $(EXE) ./*.o
