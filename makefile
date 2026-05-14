CC = g++
CFLAGS = -Wall -Wextra
all:
	$(CC) $(CFLAGS) -o a.out *.cpp
	./a.out

clean:
	find . -name '*.out' -delete 
	find . -type d -name '*.dSYM' -exec rm -rf {} +