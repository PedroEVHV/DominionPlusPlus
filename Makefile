CXX = g++
CXXFLAGS = -Wall -Wextra

INCLUDEC = -I/mnt/c/C++/DominionGithub/DominionPlusPlus/code/includes
SOURCES= $(SOURCEDIR)/main.cpp $(SOURCEDIR)/card.cpp $(SOURCEDIR)/player.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
SOURCEDIR = code/sources


%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDEC) -c $< 


main: card.o moneyCard.o victoryCard.o actionCard.o curseCard.o player.o game.o main.o 
	$(CXX) $^ -o $@


clean:
	rm -f *.o *~ *.core