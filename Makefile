#makefile

#CXX=clang++
CXX =g++
CXXFLAGS = -g -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

#BINARIES= hashtable hashtabletest wordheap wordheaptest main

#hashtabletest: hashtable.o hashtabletest.o
#	${CXX} $^ -o $@

#wordheaptest: wordheap.o hashtable.o wordheaptest.o
	#${CXX} $^ -o $@

#main: main.o wordheap.o hashtable.o
#	${CXX} $^ -o $@



clean:
	rm -f ${BINARIES} *.o
