# labelling.cpp is the latest version
# v0labelling.cpp is the first version, v1labelling.cpp the 2nd, etc

outfile: labelling.o Graph.o SquareMatrix.o
	g++ -o outfile labelling.o Graph.o SquareMatrix.o

labelling.o: labelling.cpp Graph.h
	g++ -c labelling.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp

SquareMatrix.o: SquareMatrix.cpp SquareMatrix.h
	g++ -c SquareMatrix.cpp

clean:
	rm outfile labelling.o Graph.o SquareMatrix.o

all:
	make clean
	make



