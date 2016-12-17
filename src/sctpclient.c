//SCTPClient.C
// To compile - gcc sctpclt.c -o client -lsctp
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>
#define MAX_BUFFER 1024
#define MY_PORT_NUM 62324 /* This can be changed to suit the need and should be same in server and client*/
 
void die(char *s)
{
  perror(s);
  exit(1);
}
 
 
int main()
{
  int connSock, in, i, ret, flags;
  struct sockaddr_in servaddr;
  struct sctp_status status;
  char buffer[MAX_BUFFER+1];
 
  /* Sample input*/
  strncpy(buffer, "Hello Server", 12);
  buffer[12]='\0';
 
  connSock = socket( AF_INET, SOCK_STREAM, IPPROTO_SCTP );
 
  if(connSock == -1)
    die("socket()");
 
  bzero( (void *)&servaddr, sizeof(servaddr) );
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(MY_PORT_NUM);
  servaddr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
 
  ret = connect( connSock, (struct sockaddr *)&servaddr, sizeof(servaddr) );
   
  if(ret == -1)
     die("connect()");
     
    ret = sctp_sendmsg( connSock, (void *)buffer, (size_t)strlen(buffer),
                       NULL, 0, 0, 0, 0, 0, 0 );
    close(connSock);
 
  return 0;
}
