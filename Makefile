CC      =   gcc
CFLAGS  =   -W -Wall -ansi -pedantic

ifdef ComSpec
OFLAGS  =   -lws2_32 -lwsock32
else
OFLAGS  =
endif


all: client server

client: objcli
		$(CC) -o bin/client client.o exits.o args.o socket.o $(OFLAGS)
server: objser
		$(CC) -o bin/server server.o exits.o args.o socket.o request.o $(OFLAGS)

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

debian:
	docker build -t deb-builder -f distribution/debian/Dockerfile .
	docker run --rm --name deb-builder -v `pwd`/distribution/debian/deb:/lab deb-builder

.PHONY: all
