#include "socket_util.h"
#include "request.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **args)
{
  int socket, i, j, k, id, ret, reading;
  char c;
  request_t request;
  client_t client;
  fd_set set;
  struct timeval tv;
  
  client.id = -1;

  socket = create_client("127.0.0.1", 4242);

  while (1)
    {
      FD_ZERO(&set);
      FD_SET(0, &set);
      FD_SET(socket, &set);
      tv.tv_sec = 0;
      tv.tv_usec = 10;
      if ((ret = select(socket + 1, &set, NULL, NULL, &tv)) < 0)
	die("select()");
      if (ret)
	{
	  if (FD_ISSET(0, &set))
	    {
	      c = getchar();
	      if (c == '.')
		exit(0);
	      
	      if (c == 'z' || c == 'q' || c == 's' || c == 'd' || c == 'b')
		{
		  if (c == 'b')
		    request.protocol = P_POSE_BOMB;
		  else
		    {
		      request.protocol = P_MOVE;
		      switch (c)
			{
			case 'z':
			  request.direction = UP;
			  break;
			case 's':
			  request.direction = DOWN;
			  break;
			case 'd':
			  request.direction = RIGHT;
			  break;
			default:
			  request.direction = LEFT;
			  break;
			}
		    }
		  write(socket, &request, sizeof(request_t));
		}
	    }
	  if (FD_ISSET(socket, &set))
	    {
	      reading = read(socket, &request, sizeof(request_t));
	      if (reading == 0)
		{
		  printf("server is disconnect ....\n");
		  fflush(stdout);
		  close(socket);
		  exit(0);
		}
	      else
		{
		  if (request.protocol == P_CONNECT)
		    {
		      id = request.id;
		      
		      for (i = 0; i < MAX_CLIENTS; i++)
			if (request.clients[i].id == id)
			  client = request.clients[i];
		    }
		  
		  if (request.protocol == P_GAME_OVER)
		    {
		      printf("G A M E O V E R\n");
		      fflush(stdout);
		      exit(0);
		    }
		  
		  if (request.protocol == P_UPDATE)
		    {
		      system("/bin/stty raw && /bin/stty cooked && clear");
		      
		      for (i = 0; i < 10; i++)
			if (request.clients[i].id == id && id > 0)
			  client = request.clients[i];
		      
		      printf("............................\n");
		      printf("....  B O M B E R M A N  ...\n");
		      printf("............................\n");
		      printf("Quit    : .\n");
		      printf("Up      : z\n");
		      printf("Right   : d\n");
		      printf("Down    : s\n");
		      printf("Left    : q\n\n");
		      
		      for (i = 0; i < MAP_ROW; i++)
			{
		      for (j = 0; j < MAP_COL; j++)
			{
			  int find = 0;
			  for (k = 0; k < MAX_CLIENTS; k++)
			    {
			      client_t o = request.clients[k];
			      
			      if (o.id > 0 && o.posx == j && o.posy == i)
				{
				  if (client.id == o.id)
				    printf(" X |");
				  else
				    printf(" x |");
				  find = 1;
				  break;
				}
			    }
			  if (find == 0)
			    printf(" %c |", request.map[i][j]);
			}
		      printf("\n");
		      for (k = 0; k < MAP_COL; k++)
			printf(" _  ");
		      printf("\n");
			}
		      fflush(stdout);
		    }
		}
	    }
	}
    } 
}
