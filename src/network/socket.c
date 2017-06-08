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

/**
 * \fn int create_server(char *hostname, int port)
 * \brief create a server
 * \param hostname hostname
 * \param port port
 */
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
   memcpy((char *)&serv_addr.sin_addr.s_addr,
          (char *)server->h_addr,
          server->h_length);
   serv_addr.sin_port = htons(port);
   
   if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
     panic("couldn't take the socket");

   listen(sockfd, 10);
   return (sockfd);
}

/**
 * \fn int create_client(char *hostname, int port)
 * \brief contacting the server and creating a client
 * \param hostname hostname
 * \param port port
 */
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
     panic("couldn't find the host of the server");
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   memcpy((char *)&serv_addr.sin_addr.s_addr,
          (char *)server->h_addr,
          server->h_length);

   serv_addr.sin_port = htons(port);

   if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
     panic("couldn't connect with the server");
   
   return (sockfd);
}
