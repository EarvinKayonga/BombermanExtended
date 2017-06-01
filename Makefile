CC      =   gcc
CFLAGS  =   -W -Wall -Werror

all: client server

client: objcli
		$(CC) -o bin/client client.o exits.o args.o socket.o
server: objser
		$(CC) -o bin/server server.o socket.o request.o args.o

objcli:
	$(CC) -c common/*.c client/*.c

objser:
	$(CC) -c common/* server/server.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client

re: fclean all

.PHONY: all
