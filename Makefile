all: client server

client: objcli
		gcc -o bin/client client.o socket.o print.o
server: objser
		gcc -o bin/server server.o socket.o request.o

objcli:
	gcc -c client/client.c common/socket.c common/print.c


objser:
	gcc -c server/server.c common/socket.c common/request.c
clean:
	rm -rf *.o

fclean: clean
	rm -rf bin/server bin/client

re: fclean all

.PHONY: all
