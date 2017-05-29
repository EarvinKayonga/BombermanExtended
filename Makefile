CC      =   gcc
CFLAGS  =   -W -Wall -Werror

all: client server

client: objcli
		$(CC) `sdl-config --cflags --libs`  -o bin/client client.o exits.o args.o graphics.o socket.o
server: objser
		$(CC) -o bin/server server.o socket.o request.o args.o

objcli:
	$(CC) -c common/args.c common/socket.c common/print.c client/client.c client/sdl/*.c

objser:
	$(CC) -c common/args.c common/socket.c common/request.c server/server.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client

re: fclean all

.PHONY: all
