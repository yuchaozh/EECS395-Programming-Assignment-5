
CPPFLAGS=-g 
CFLAGS=-g

ALL: main.o wordArray.o node.o map.o list.o 
	g++ -g -o proj5 main.o wordArray.o node.o map.o list.o -w

%.o:

clean:
	rm -r *.o proj5

