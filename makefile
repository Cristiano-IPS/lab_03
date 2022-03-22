release:
	gcc -o prog *.c
debug:
	gcc -o prog -g main.c
clean:
	rm -f ./prog
run:
	./prog