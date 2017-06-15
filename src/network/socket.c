/**
 * \file common/socket.c
 * \brief Contacting and Creating a server.
 * \version 0.1
 * \date June 2017, 1
 *
 * Functions for Contacting and Creating a server (by socket)
 *
 */
#include    "../common/exits.h"

#ifdef      __WIN32__
#include    "windows.h"

int         create_client(char *hostname, int port){
   return port-*hostname;
}

int            create_server(char *hostname, int port){
   SOCKET      Listen, Accept;
   DWORD       Flags, RecvBytes, SendBytes;
   SOCKADDR_IN InternetAddr;
   LPSOCKET_INFORMATION SocketInfo;
   DWORD       Event;
   WSANETWORKEVENTS NetworkEvents;
   WSADATA     wsaData;
   char        *message;

   InternetAddr.sin_family = AF_INET;
   InternetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
   InternetAddr.sin_port = htons(PORT);
   if (WSAStartup(0x0202, &wsaData) != 0)
       panic(sprintf(message, "select() returned with error %d\n", WSAGetLastError()));

   if ((Listen = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
      panic(sprintf(message, "socket() failed with error %d\n", WSAGetLastError()));

   if(CreateSocketInformation(Listen) == FALSE)
      panic("CreateSocketInformation() failed!\n");

   if (WSAEventSelect(Listen, EventArray[EventTotal - 1], FD_ACCEPT|FD_CLOSE) == SOCKET_ERROR)
      panic(sprintf(message, "WSAEventSelect() failed with error %d\n", WSAGetLastError()));

   if (bind(Listen, (PSOCKADDR) &InternetAddr, sizeof(InternetAddr)) == SOCKET_ERROR)
      panic(sprintf(message, "bind() failed with error %d\n", WSAGetLastError()));

   if (listen(Listen, 5))
      panic(sprintf(message, "listen() failed with error %d\n", WSAGetLastError()));

   NonBlock = 1;
   if (ioctlsocket(ListenSocket, FIONBIO, &NonBlock) == SOCKET_ERROR)
      panic(sprintf(message, "ioctlsocket() failed with error %d\n", WSAGetLastError()));

   return (ListenSock);
}
#else
#include    "linux.h"

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
#endif

