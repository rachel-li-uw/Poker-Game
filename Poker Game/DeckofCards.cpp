#include <iostream>
#include <cstdlib>

#include "DeckofCards.h"

using namespace std;

DeckofCards::DeckofCards() {
    for (int i = 0; i < 52; ++i) {
        deck[i].face = i%13;
        deck[i].suit = i/13;
    }
}

DeckofCards::~DeckofCards() {
    delete[] deck;
}

void DeckofCards::shuffle() {
    for (int i = 0; i < currentCard; ++i) {
        int other = rand() % currentCard;
        int tempFace = deck[other].face;
        int tempSuit = deck[other].suit;
        deck[other].face = deck[i].face;
        deck[other].suit = deck[i].suit;
        deck[i].face = tempFace;
        deck[i].suit = tempSuit;
    }
}

Card DeckofCards::dealCard() {
    return deck[currentCard--];
}

bool DeckofCards::moreCards() {
    return (currentCard >= 0);
}

