CXX = g++
CXXFLAGS = -Wall -Wextra

INCLUDEC = -I/mnt/c/C++/DominionGithub/DominionPlusPlus/code/includes
INCLUDED = -I/mnt/d/C++/DominionGithub/DominionPlusPlus/code/includes
SOURCES= $(SOURCEDIR)/main.cpp $(SOURCEDIR)/card.cpp $(SOURCEDIR)/player.cpp
SOURCEDIR = code/sources


%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDED) -c $< 


main: card.o ACM.o moneyCard.o victoryCard.o actionCard.o curseCard.o player.o game.o main.o 
	$(CXX) $^ -o $@


clean:
	rm -f *.o *~ *.core