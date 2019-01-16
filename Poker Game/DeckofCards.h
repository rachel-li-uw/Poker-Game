#ifndef DeckofCards_h
#define DeckofCards_h

#include "Card.h"

class DeckofCards{
private:
    const int SIZE_OF_DECK = 52;
public:
    Card* deck = new Card[52];
    int currentCard = 51;
    DeckofCards();
    ~DeckofCards();
    void shuffle();
    bool moreCards();
    Card dealCard();
};

#endif /* DeckofCards_h */
