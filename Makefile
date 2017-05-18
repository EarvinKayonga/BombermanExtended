CC      =   gcc
CFLAGS  =   -W -Wall -Werror

all: client server

client: objcli
		$(CC) `sdl-config --cflags --libs` -framework Cocoa -o bin/client client.o socket.o print.o graphics.o
server: objser
		$(CC) -o bin/server server.o socket.o request.o

objcli:
	$(CC) -c client/client.c common/socket.c common/print.c client/sdl/graphics.c

objser:
	$(CC) -c server/server.c common/socket.c common/request.c

clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client

re: fclean all

.PHONY: all
