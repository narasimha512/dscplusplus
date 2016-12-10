OBJS = DoubleKey.o Main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -I ../inc
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o p1

DoubleKey.o :
	$(CC) $(CFLAGS) DoubleKey.cpp

Main.o :
	$(CC) $(CFLAGS) Main.cpp
clean:
	\rm *.o *~ p1
