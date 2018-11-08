compile: test.c
	clear;
	gcc -c test.c;
	gcc -o test *.o -lm;
	./test

