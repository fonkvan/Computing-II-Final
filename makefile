CC = g++
CFLAGS = -g -Wall

Account.o: Account.h Account.cpp
	$(CC) $(CFLAGS) -c Account.cpp
Node.o: Node.h Node.cpp
	$(CC) $(CFLAGS) -c Node.cpp
Admin.o: Account.h Admin.h Admin.cpp
	$(CC) $(CFLAGS) -c Admin.cpp
Hash.o: Hash.h Hash.cpp
	$(CC) $(CFLAGS) -c Hash.cpp
main.o: main.cpp Account.h Admin.h Hash.h
	$(CC) $(CFLAGS) -c main.cpp
hashFunction: main.o Account.o Node.o Admin.o Hash.o
	$(CC) $(CFLAGS) main.o Account.o Node.o Admin.o Hash.o -o hashFunction
clean:
	rm -f *.o
	rm -f hashFunction
gdb:
	gdb hashFunction
run:
	./hashFunction
