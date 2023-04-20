
files := BigInt.o ByteQueue.o unittest.o utils.o bigint_parser.o tests.o

main: $(files) main.o main.out 
	./main.out

test: $(files) test.o test.out
	./test.out


test.out: $(files) test.o
	gcc -o test.out $(files) test.o

main.out: $(files) main.o
	gcc -o main.out $(files) main.o

test.o: test.c
	gcc -c test.c

main.o: main.c
	gcc -c main.c

$(files): %.o: %.c

clean:
	rm -f *.o main.out test.out

