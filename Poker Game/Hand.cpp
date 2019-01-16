#include <iostream>
#include <string>
#include "DeckofCards.h"
#include "Hand.h"

using namespace std;

Hand::Hand() {
    Card cards[5];
    Card compOrder[5];
    for (int i = 0; i < 5; ++i) {
        cards[i].face = 0;
        cards[i].suit = 0;
        compOrder[i].face = 0;
        compOrder[i].suit = 0;
    }
}

void Hand::sort() {
    int maxIndex, tempFace, tempSuit;
    for (int i = 4; i >= 0; i--) {
        maxIndex = i;
        for (int j = 0; j < i; j++) {
            if ((cards[j].face) > (cards[maxIndex].face)) {
                maxIndex = j;
            }
        }
        tempFace = cards[i].face;
        tempSuit = cards[i].suit;
        cards[i].face = cards[maxIndex].face;
        cards[i].suit = cards[maxIndex].suit;
        cards[maxIndex].face = tempFace;
        cards[maxIndex].suit = tempSuit;
    }
}

int Hand::getRank() {
    
    Hand::sort();
    bool sameSuit = Hand::getSameSuit();
    bool run = Hand::getRun();
    int sameFace = Hand::getSameFace();
    int pairs = Hand::getPairs();
    
    for (int i = 0; i < 5; ++i) {
        compOrder[i].face = 0;
    }
    
    if ((sameSuit) && (run) && (cards[0].face == 1)) {
        return 1;
    } else if (sameSuit && run) {
        compOrder[0].face = cards[4].face;
        return 2;
    } else if (sameFace == 4) {
        if (cards[0].face == cards[1].face) {
            compOrder[0].face = cards[0].face;
        } else {
            compOrder[0].face = cards[1].face;
        }
        return 3;
    } else if ((sameFace == 3) && (pairs == 2)) {
        if (cards[1].face == cards[2].face) {
            compOrder[0].face = cards[0].face;
            compOrder[1].face = cards[3].face;
        } else {
            compOrder[0].face = cards[2].face;
            compOrder[1].face = cards[0].face;
        }
        return 4;
    } else if (sameSuit) {
        for (int i = 0; i < 5; ++i) {
            compOrder[i].face = cards[4-i].face;
        }
        return 5;
    } else if (run) {
        compOrder[0].face = cards[4].face;
        return 6;
    } else if (sameFace == 3) {
        if (cards[1].face == cards[2].face) {
            compOrder[0].face = cards[0].face;
            compOrder[1].face = cards[4].face;
            compOrder[2].face = cards[3].face;
        } else {
            compOrder[0].face = cards[2].face;
            compOrder[1].face = cards[1].face;
            compOrder[2].face = cards[0].face;
        }
        return 7;
    } else if (pairs == 2) {
        if (cards[3].face != cards[4].face) {
            compOrder[0].face = cards[2].face;
            compOrder[1].face = cards[0].face;
            compOrder[2].face = cards[4].face;
        } else if (cards[1].face != cards[2].face) {
            compOrder[0].face = cards[3].face;
            compOrder[1].face = cards[0].face;
            compOrder[2].face = cards[2].face;
        } else {
            compOrder[0].face = cards[3].face;
            compOrder[1].face = cards[1].face;
            compOrder[2].face = cards[0].face;
        }
        return 8;
    } else if (pairs == 1) {
        int count = 4;
        for (int i = 0; i < 4; ++i) {
            if (cards[i].face == cards[i+1].face) {
                for (int j = 0; j < 5; ++j) {
                    if (j != i && j!= (i+1)) {
                        compOrder[count--].face = cards[j].face;
                    }
                }
                compOrder[0].face = cards[i].face;
                compOrder[1].face = cards[i].face;
                break;
            }
        }
        return 9;
    } else {
        for (int i = 0; i < 5; ++i) {
            compOrder[i].face = cards[4-i].face;
        }
        return 10;
    }
    
}

bool Hand::getSameSuit () {
    int suit = this->cards[0].suit;
    for (int i = 1; i < 5; ++i) {
        if (this->cards[i].suit != suit) {
            return false;
        }
    }
    return true;
}

bool Hand::getRun () {
    for (int i = 0; i < 4; ++i) {
        if ((this->cards[i].face + 1) != (this->cards[i+1].face)) {
            return false;
        }
    }
    return true;
}

int Hand::getSameFace () {
    for (int i = 0; i < 3; ++i) {
        if (this->cards[i].face == this->cards[i+2].face) {
            if ((i < 2) && (this->cards[i].face == this->cards[i+3].face)) {
                return 4;
            }
            return 3;
        }
    }
    return 1;
}

int Hand::getPairs () {
    int pairs = 0;
    for (int i = 0; i < 4; ++i) {
        if ((cards[i].face) == (cards[i+1].face)) {
            pairs++;
            i++;
        }
    }
    return pairs;
}

int Hand::compareRank(Hand other) {
    if (ranking < other.ranking) {
        return 1;
    } else if (ranking > other.ranking){
        return -1;
    } else {
        for (int i = 0; i < 5; ++i) {
            if (compOrder[i].face > other.compOrder[i].face) {
                return 1;
            } else if (compOrder[i].face < other.compOrder[i].face){
                return -1;
            }
        }
        return 0;
    }
}
