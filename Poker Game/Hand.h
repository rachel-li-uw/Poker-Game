#ifndef Hand_h
#define Hand_h

#include "Card.h"
#include "DeckofCards.h"

class Hand{
private:

public:
    
    Card cards[5];
    Card compOrder[5];

    int ranking;
    
    Hand();
    void sort();
    bool getSameSuit();
    bool getRun();
    int getSameFace();
    int getPairs();
    int getRank();
    int compareRank(Hand other);
   
};

#endif /* Hand_h */
