OBJS = DoubleKey.o Main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -I ../inc
LFLAGS = -Wall $(DEBUG)
BIN=../bin/

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(BIN)/test

$(BIN)/ipv6client : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv6client Simple_tcpclient_ipv6.c

$(BIN)/ipv6server : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv6server Simple_tcpserver_ipv6.c

$(BIN)/ipv4client : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv4client Simple_tcpclient_ipv4.c

$(BIN)/ipv4server : 
	$(CC) $(LFLAGS)  -o $(BIN)/ipv4server Simple_tcpserver_ipv4.c

DoubleKey.o :
	$(CC) $(CFLAGS) DoubleKey.cpp

Main.o :
	$(CC) $(CFLAGS) Main.cpp

clean:
	\rm *.o $(BIN)/*

all: tcp

tcp: $(BIN)/ipv4client $(BIN)/ipv4server $(BIN)/ipv6client $(BIN)/ipv6server
