/**
 * \file common/socket.c
 * \brief Contacting and Creating a server.
 * \version 0.1
 * \date June 2017, 1
 *
 * Functions for Contacting and Creating a server (by socket)
 *
 */
#include    "socket_util.h"

int         create_server(char *hostname, int port)
{
   int      sockfd;
   struct   sockaddr_in serv_addr;
   struct   hostent *server;
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if (sockfd < 0)
     panic("socket()");
   
   server = gethostbyname(hostname);
   
   if (server == NULL)
     panic("server()");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr,
	 (char *)&serv_addr.sin_addr.s_addr,
	 server->h_length);
   serv_addr.sin_port = htons(port);
   
   if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
     panic("bind()");

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
     panic("socket()");
   
   server = gethostbyname(hostname);
   
   if (server == NULL)
     panic("server()");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr,
	 (char *)&serv_addr.sin_addr.s_addr,
	 server->h_length);
   serv_addr.sin_port = htons(port);

   if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
     panic("connect()");
   
   return (sockfd);
}
