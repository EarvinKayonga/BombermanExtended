#include    "socket_util.h"

void        die(char *message)
{
  perror(message);
  fflush(stdout) ;
  exit(1);
}

int         create_server(char *hostname, int port)
{
   int      sockfd;
   struct   sockaddr_in serv_addr;
   struct   hostent *server;
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0)
     die("socket()");
   
   server = gethostbyname(hostname);
   
   if (server == NULL)
     die("server()");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr,
	 (char *)&serv_addr.sin_addr.s_addr,
	 server->h_length);
   serv_addr.sin_port = htons(port);
   
   if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
     die("bind()");
   }
   listen(sockfd, 10);
   return (sockfd);
}

int         create_client(char *hostname, int port)
{
   int      sockfd;
   struct   sockaddr_in serv_addr;
   struct   hostent *server;
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0)
     die("socket()");
   
   server = gethostbyname(hostname);
   
   if (server == NULL)
     die("server()");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr,
	 (char *)&serv_addr.sin_addr.s_addr,
	 server->h_length);
   serv_addr.sin_port = htons(port);
   if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
     die("connect()");
   
   return (sockfd);
}
