#makefile

CXX=clang++
#CXX =g++
CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
BINARIES = main BtreeTest

BtreeTest: Btree.o BtreeTest.o 
	${CXX} $^ -o $@

main: 
	g++ -o main Main.cpp UserInteraction.cpp Graph.cpp


clean:
	rm -f main {BINARIES} *.o
