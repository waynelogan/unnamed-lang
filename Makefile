all: build run

build: main.c
	gcc main.c -o main -Wall -Wextra

run: main
	./main

clean:
	rm -f main