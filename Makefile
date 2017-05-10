all: client server

client: objcli
		gcc -o client client.o socket.o print.o
server: objser
		gcc -o server server.o socket.o

objcli:
	gcc -c client.c socket.c print.c


objser:
	gcc -c server.c socket.c
clean:
	rm -rf *.o

fclean: clean
	rm -rf server client

re: fclean all

.PHONY: all
