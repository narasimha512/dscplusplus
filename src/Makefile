OBJS = DoubleKey.o Main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -I ../inc
LFLAGS = -Wall $(DEBUG)
BIN=../bin/

p1.e : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(BIN)/p1.e

$(BIN)/ipv6client.e : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv6client.e Simple_tcpclient_ipv6.c

$(BIN)/ipv6server.e : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv6server.e Simple_tcpserver_ipv6.c

DoubleKey.o :
	$(CC) $(CFLAGS) DoubleKey.cpp

Main.o :
	$(CC) $(CFLAGS) Main.cpp

clean:
	\rm *.o *~ p1 

all: $(BIN)/ipv6client.e $(BIN)/ipv6server.e
