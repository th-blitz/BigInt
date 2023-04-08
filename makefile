
files := BigInt.o ByteStack.o ByteQueue.o DecimalArray.o unittest.o utils.o main.o

all: a.out

a.out: $(files)
	gcc -o a.out $(files)

$(files): %.o: %.c

clean:
	rm -f *.o a.out

