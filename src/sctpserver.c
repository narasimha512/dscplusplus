//SCTPServer.C
// To compile - gcc sctpserver.c -o server -lsctp 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#define MAX_BUFFER 1024
#define MY_PORT_NUM 62324 /* This can be changed to suit the need and should be same in server and client */
 
void die(char *s)
{
      perror(s);
      exit(1);
}
 
int main()
{
  int listenSock, connSock, ret, in , flags, i;
  struct sockaddr_in servaddr;
  struct sctp_initmsg initmsg;
  struct sctp_event_subscribe events;
  struct sctp_sndrcvinfo sndrcvinfo;
  //char buffer[MAX_BUFFER+1];
 
  listenSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP );
 
  bzero( (void *)&servaddr, sizeof(servaddr) );
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl( INADDR_ANY );
  servaddr.sin_port = htons(MY_PORT_NUM);
 
  ret = bind( listenSock, (struct sockaddr *)&servaddr, sizeof(servaddr) );
 
  /* Specify that a maximum of 5 streams will be available per socket */
  memset( &initmsg, 0, sizeof(initmsg) );
  initmsg.sinit_num_ostreams = 5;
  initmsg.sinit_max_instreams = 5;
  initmsg.sinit_max_attempts = 4;
  ret = setsockopt( listenSock, IPPROTO_SCTP, SCTP_INITMSG, 
                     &initmsg, sizeof(initmsg) );
 
  listen( listenSock, 5 );
 
  while( 1 ) {
 
  char buffer[MAX_BUFFER + 1];
  int len ;  
 
  bzero(buffer, MAX_BUFFER + 1);
 
  printf("Awaiting a new connection\n");
 
  connSock = accept( listenSock, (struct sockaddr *)NULL, (unsigned int *)NULL );
  if(connSock == -1)
      die("accept()");
    else
      printf("New client connected....\n");
      in = sctp_recvmsg( connSock, buffer, sizeof(buffer),
                        (struct sockaddr *)NULL, 0, &sndrcvinfo, &flags );
      printf(" Data : %s\n", (char*)buffer);
      close( connSock );
  }
 
  return 0;
}
