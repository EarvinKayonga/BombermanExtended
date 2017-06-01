CC      =   gcc
CFLAGS  =   -W -Wall -Werror -ansi -pedantic

all: client server

client: objcli
		$(CC) -o bin/client client.o exits.o args.o socket.o
server: objser
		$(CC) -o bin/server server.o socket.o request.o args.o

objcli:
	$(CC) -c src/common/*.c src/network/*.c src/client/*.c

objser:
	$(CC) -c src/common/*.c src/network/*.c src/server/server.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client doc/html

re: fclean all

doc:
	doxygen

.PHONY: all
