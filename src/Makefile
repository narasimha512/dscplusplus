OBJS = DoubleKey.o Main.o
CC = g++
GCC = gcc
DEBUG = -g
INC = -I ../inc
CFLAGS = -Wall -c $(DEBUG) $(INC)
LFLAGS = -Wall $(DEBUG) -lsctp Util.o
BIN=../bin/

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(BIN)/test

$(BIN)/ipv6client : 
	$(CC) $(LFLAGS) -o $(BIN)/ipv6client Simple_tcpclient_ipv6.c

$(BIN)/ipv6server : 
	$(CC) $(LFLAGS) -o $(BIN)/ipv6server Simple_tcpserver_ipv6.c

$(BIN)/ipv4client : 
	$(CC) $(LFLAGS) -o $(BIN)/ipv4client Simple_tcpclient_ipv4.c

$(BIN)/ipv4server : 
	$(CC) $(LFLAGS) -o $(BIN)/ipv4server Simple_tcpserver_ipv4.c

DoubleKey.o :
	$(CC) $(CFLAGS) DoubleKey.cpp

Util.o :
	$(CC) $(CFLAGS) Util.cpp

Main.o :
	$(CC) $(CFLAGS) Main.cpp

$(BIN)/ArrayHeap : 
	$(CC) $(INC) -o $(BIN)/ArrayHeap $(LFLAGS) Heap-Array.cpp

$(BIN)/sctpclient : 
	$(CC) -o $(BIN)/sctpclient $(LFLAGS) sctpclient.c

$(BIN)/sctpserver : 
	$(CC) -o $(BIN)/sctpserver $(LFLAGS) sctpserver.c


clean:
	\rm *.o $(BIN)/*

all: tcp sctp ds

ds: $(BIN)/ArrayHeap

tcp: $(BIN)/ipv4client $(BIN)/ipv4server $(BIN)/ipv6client $(BIN)/ipv6server

sctp: $(BIN)/sctpserver $(BIN)/sctpclient
