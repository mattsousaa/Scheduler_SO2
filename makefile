all: op

op: main.c	
	gcc *.c -c -pthread
	gcc *.o -o  main -lm -pthread
	./main
clean:
	rm *.o
	rm main
