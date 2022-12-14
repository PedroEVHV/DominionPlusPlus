CXX=g++
CXXFLAGS=-Wall -Wextra -Werror

main: main.o
	$(CXX) -o main main.o

main.o: code/main/main.cpp
	$(CXX) $(CXXFLAGS) -c code/main/main.cpp

.PHONY: run clean

run: main
	./$<

clean:
	rm -f *.o *~ *.core 