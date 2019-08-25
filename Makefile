CC=gcc
CXX=g++ -std=c++11
CFLAGS=-I.

slist: slist.o 
	$(CXX) -o slist slist.o 