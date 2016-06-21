CC = g++
CFLAGS = -Wall -g -std=c++11

all: weightedgraph

graph.o: graph.cc wdigraph.h includes.h
	${CC} ${CFLAGS} -c graph.cc

wdigraph1.o: wdigraph1.cc wdigraph.h includes.h
	${CC} ${CFLAGS} -c wdigraph1.cc

wdigraph2.o: wdigraph2.cc wdigraph.h includes.h
	${CC} ${CFLAGS} -c wdigraph2.cc

weightedgraph: graph.o wdigraph1.o wdigraph2.o
	${CC} ${CFLAGS} graph.o wdigraph1.o wdigraph2.o -o weighted_graph

clean:
	rm -rf *.o
	rm -rf weighted_graph
