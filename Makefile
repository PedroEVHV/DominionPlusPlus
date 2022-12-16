CXX=g++
CXXFLAGS=-Wall -Wextra
INCPATH = -ID:/C++/DominionGithub/DominionPlusPlus

main: main.o card.o player.o  moneyCard.o victoryCard.o actionCard.o
	$(CXX) $(INCPATH) -o main main.o 

main.o: code/main/main.cpp
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/main/main.cpp 



#card rules

card.o: code/class/cards/card.cpp  
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/class/cards/card.cpp 

moneyCard.o: code/class/cards/cardTypes/moneyCard.cpp  
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/class/cards/cardTypes/moneyCard.cpp 

actionCard.o: code/class/cards/cardTypes/actionCard.cpp  
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/class/cards/cardTypes/actionCard.cpp 

victoryCard.o: code/class/cards/cardTypes/victoryCard.cpp  
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/class/cards/cardTypes/victoryCard.cpp 

#player rules

player.o: code/class/players/player.cpp 
	$(CXX) $(CXXFLAGS) $(INCPATH) -c code/class/players/player.cpp 



.PHONY: run clean

run: main
	./$<

clean:
	rm -f *.o *~ *.core 

.c.o:
	gcc -c $< -o $(<:.c=.o)