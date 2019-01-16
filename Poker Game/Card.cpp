#include <iostream>
#include <sstream>
#include "Card.h"
using namespace std;

Card::Card() {
    face = 0;
    suit = 0;
}

Card::Card(int face, int suit) {
    this->face = face;
    this->suit = suit;
}

string Card::toString(){
    stringstream ss;
    ss << faces[face] << " of " << suits[suit];
    string s = ss.str();
    return s;
}


