OBJS = Interface_ImageCommand.o Manager.o Parser.o RemoveRedCommand.o Main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o imagedit

Interface_ImageCommand.o : Interface_ImageCommand.h
	$(CC) $(CFLAGS) Interface_ImageCommand.cpp

Manager.o : Manager.h
	$(CC) $(CFLAGS) Manager.cpp

Parser.o : Parser.h
	$(CC) $(CFLAGS) Parser.cpp 

RemoveRedCommand.o : RemoveRedCommand.h
	$(CC) $(CFLAGS) RemoveRedCommand.cpp

Main.o :
	$(CC) $(CFLAGS) Main.cpp

clean:
	rm *.o