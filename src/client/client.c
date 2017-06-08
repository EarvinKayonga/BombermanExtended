/**
 * \file client/client.c
 * \brief client's Implementation.
 * \version 0.1
 * \date June 2017, 1
 *
 * The main and select functions for the client
 *
 */
#include 	    "client.h"

/**
 * \fn int main(int argc, char **args)
 * \brief Contacts the server with the given arguments
 * \param argc number of arguments
 * \param args list of arguments.
 * \return a socket if no errors occured, else 1.
 */
int             main(int argc, char **args)
{
    int         socket;
    config_t    configuration;

    #ifdef __WIN32__
       WORD versionWanted = MAKEWORD(1, 1);
       WSADATA wsaData;
       WSAStartup(versionWanted, &wsaData);
    #endif

    configuration = from_arguments(argc, args);
    socket = create_client(configuration.hostname, configuration.port);

    return       (init_loop(socket));
}

int             game_loop(int           ret,
                          int           socket,
                          client_t      client,
                          fd_set        set)
{
    request_t   request;
    int reading;

    if (ret)
    {
        if (FD_ISSET(0, &set))
            send_command(getchar(), socket);
        if (FD_ISSET(socket, &set))
        {
            reading = read(socket, &request, sizeof(request_t));
            if (reading == 0)
                lost_connection("lost connection with the server", socket);
            else
                if (request.protocol == P_CONNECT)
                    assign_client(request, &client);
                if (request.protocol == P_GAME_OVER)
                    gameover(socket);
                if (request.protocol == P_UPDATE)
                    paint(&request, &client);
        }
    }
    return (0);
}

/**
 * \fn int init_loop(int socket)
 * \brief init networks related variables and the client struct, then reads from the server socket
 * \param socket server socket.
 * \return 0 if no errors occured, else 1.
 *
 *  Server with call to select
 */
int             init_loop(int socket)
{
    int         ret;
    fd_set      set;
    client_t    client;
    struct timeval tv;

    client.id = -1;
    tv.tv_sec = 0;
    tv.tv_usec = 10;
    while(1)
    {
        FD_ZERO(&set);
        FD_SET(0, &set);
        FD_SET(socket, &set);

        if ((ret = select(socket + 1, &set, NULL, NULL, &tv)) < 0)
            panic("select()");

        game_loop(ret, socket, client, set);
    }

    return (0);
}


