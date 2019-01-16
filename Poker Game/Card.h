#ifndef Card_h
#define Card_h

using namespace std;

class Card{
private:
    string faces[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string suits[4] {"Spades", "Hearts", "Clubs", "Diamonds"};
public:
    int face;
    int suit;
    Card();
    Card(int face, int suit);
    string toString();
};

#endif /* Card_h */
