all: client server

client: objcli
		gcc -o bin/client client.o socket.o print.o
server: objser
		gcc -o bin/server server.o socket.o request.o

objcli:
	gcc -c client.c socket.c print.c


objser:
	gcc -c server.c socket.c request.c
clean:
	rm -rf *.o

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all
