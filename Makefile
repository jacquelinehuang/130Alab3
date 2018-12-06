#makefile

#CXX=clang++
CXX =g++

CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wno-unused-parameter #-Wno-unused-private-field
BINARIES = main BtreeTest

BtreeTest: Btree.o BtreeTest.o 
	${CXX} $^ -o $@
main: Main.o Btree.o Graph.o
	g++ $^ -o $@
clean:
	rm -f main {BINARIES} *.o
