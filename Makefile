$(shell mkdir -p bin)


all: msg


msg:
	gcc -static *msg*.c -o bin/msg


clean:
	rm -rf bin

