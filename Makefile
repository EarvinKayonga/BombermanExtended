CC      =   gcc
CFLAGS  =   -W -Wall -ansi -pedantic

all: client server

client: objcli
		$(CC) -o bin/client client.o exits.o args.o socket.o -lws2_32
server: objser
		$(CC) -o bin/server server.o exits.o args.o socket.o request.o -lws2_32

objcli:
	$(CC) $(CFLAGS) -c src/common/*.c src/network/*.c src/client/*.c -lws2_32

objser:
	$(CC) $(CFLAGS) -c src/common/*.c src/network/*.c src/server/server.c -lws2_32

clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client doc/html

re: fclean all

doc:
	doxygen

.PHONY: all
