
files := BigInt.o ByteStack.o DecimalArray.o main.o

all: a.out

a.out: $(files)
	gcc -o a.out $(files)

$(files): %.o: %.c

clean:
	rm -f *.o a.out

