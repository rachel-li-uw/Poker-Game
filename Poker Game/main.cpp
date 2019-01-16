#include <iostream>
#include <string>
#include "Card.h"
#include "DeckofCards.h"
#include "Hand.h"
using namespace std;

int main () {
    
    DeckofCards d;
    d.shuffle();
    
    string replay;
    
    Hand player;
    Card* dealerHole = new Card[2];
    Hand dealer;
    Hand dealerMaxHand;
    Hand community;
    
    int playerMoney = 1000;
    int dealerMoney = 1000;
    
    int dealerBet = 0;
    int playerBet = 0;

    cout << "POKER!" << endl << endl;
    cout << "The dealer and you both have $1000!" << endl;
    
    do {
      
        // dealing player's 2 hole cards
        cout << "HERE ARE YOUR HOLE CARDS:" << endl;
        for (int i = 0; i < 2; ++i) {
            if (d.moreCards()) {
                player.cards[i] = d.dealCard();
            } else {
                d.shuffle();
                d.currentCard = 51;
                player.cards[i] = d.dealCard();
            }
            cout << player.cards[i].toString() << endl;
        }
        cout << endl;
        
        // dealing dealer's 2 hole cards
        for (int i = 0; i < 2; ++i) {
            if (d.moreCards()) {
                dealerHole[i] = d.dealCard();
            } else {
                d.shuffle();
                d.currentCard = 51;
                dealerHole[i] = d.dealCard();
            }
        }
   
        // dealer's 1st betting
        if (dealerHole[0].face == dealerHole[1].face || dealerHole[0].suit == dealerHole[1].suit) {
            cout << "DEALER BETS $100!" << endl;
            dealerBet = 100;
        } else {
            cout << "DEALER BETS $50!" << endl;
            dealerBet = 50;
        }
        
        // player's 1st betting
        cout << "How much do you want to bet? \nYou have $" << playerMoney << ". Enter an integer value: ";
        cin >> playerBet;
        
        // dealing all 5 community cards
        for (int i = 0; i < 5; ++i) {
            if (d.moreCards()) {
                community.cards[i] = d.dealCard();
            } else {
                d.shuffle();
                d.currentCard = 51;
                community.cards[i] = d.dealCard();
            }
        }
        
        // showing first 3 community cards
        cout << "\nFLOP!" << endl;
        cout << community.cards[0].toString() << endl;
        cout << community.cards[1].toString() << endl;
        cout << community.cards[2].toString() << endl;
        
        // dealer's 2nd betting
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[1].face;
        dealer.cards[3].suit = community.cards[1].suit;
        dealer.cards[4].face = community.cards[2].face;
        dealer.cards[4].suit = community.cards[2].suit;
        for (int i = 0; i < 5; ++i) {
            dealerMaxHand.cards[i].face = dealer.cards[i].face;
            dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
        }
        
        dealer.ranking = dealer.getRank();
        dealerMaxHand.ranking = dealerMaxHand.getRank();

        if (dealerMaxHand.ranking < 9) {
            cout << "DEALER DOUBLES BET TO $" << dealerBet << "!"<< endl;
            dealerBet*=2;
        } else {
            dealerBet/=2;
            cout << "DEALER FOLDS TO $" << dealerBet << "!" << endl;
        }
        cout << endl;
        
        // player's 2nd betting
        bool bet;
        cout << "HOW ARE THE CARDS? Enter 0 to fold or enter 1 to double: ";
        cin >> bet;
        if (bet) {
            playerBet*=2;
            cout << "YOU DOUBLED YOUR BET TO $" << playerBet << ".";
        } else {
            playerBet/=2;
            cout << "YOU FOLDED YOUR BET TO $" << playerBet << ".";
        }
        
        // show 1 more community card
        cout << "\n\nTURN!" << endl;
        cout << community.cards[3].toString() << endl;
        
        // dealer's 3rd betting

        // 0 1 3
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[1].face;
        dealer.cards[3].suit = community.cards[1].suit;
        dealer.cards[4].face = community.cards[3].face;
        dealer.cards[4].suit = community.cards[3].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 0 2 3
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[2].face;
        dealer.cards[3].suit = community.cards[2].suit;
        dealer.cards[4].face = community.cards[3].face;
        dealer.cards[4].suit = community.cards[3].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 1 2 3
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[1].face;
        dealer.cards[2].suit = community.cards[1].suit;
        dealer.cards[3].face = community.cards[2].face;
        dealer.cards[3].suit = community.cards[2].suit;
        dealer.cards[4].face = community.cards[3].face;
        dealer.cards[4].suit = community.cards[3].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        if (dealerMaxHand.ranking < 7) {
            cout << "DEALER DOUBLES BET!!" << endl;
            dealerBet*=2;
        } else {
            cout << "DEALER FOLDS!!" << endl;
            dealerBet /= 2;
        }
        
        // player's 3rd betting
        cout << "HOW IS THE CARD? Enter 0 to fold or enter 1 to double: ";
        cin >> bet;
        
        if (bet) {
            playerBet*=2;
            cout << "YOU DOUBLED YOUR BET TO $" << playerBet << ".";
        } else {
            playerBet/=2;
            cout << "YOU FOLDED YOUR BET TO $" << playerBet << ".";
        }
        
        
        // last community card
        cout << endl << endl;
        cout << "RIVER!" << endl;
        cout << community.cards[4].toString() << endl << endl;
        
        // player's hand
        cout << "WHICH COMMUNITY CARDS WOULD YOU LIKE TO KEEP?" << endl;
        int card;
        cout << "Enter the first card you want (Enter 1, 2, 3, 4 or 5): ";
        cin >> card;
        player.cards[2] = community.cards[card-1];
        cout << "Enter the second card you want (Enter 1, 2, 3, 4 or 5): ";
        cin >> card;
        player.cards[3] = community.cards[card-1];
        cout << "Enter the last card you want (Enter 1, 2, 3, 4 or 5): ";
        cin >> card;
        player.cards[4] = community.cards[card-1];
        player.ranking = player.getRank();
        
        // dealer's hand
        
        // 0 1 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[1].face;
        dealer.cards[3].suit = community.cards[1].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 0 2 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[2].face;
        dealer.cards[3].suit = community.cards[2].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 0 3 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[0].face;
        dealer.cards[2].suit = community.cards[0].suit;
        dealer.cards[3].face = community.cards[3].face;
        dealer.cards[3].suit = community.cards[3].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 1 2 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[1].face;
        dealer.cards[2].suit = community.cards[1].suit;
        dealer.cards[3].face = community.cards[2].face;
        dealer.cards[3].suit = community.cards[2].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // 1 3 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[1].face;
        dealer.cards[2].suit = community.cards[1].suit;
        dealer.cards[3].face = community.cards[3].face;
        dealer.cards[3].suit = community.cards[3].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }

        // 2 3 4
        dealer.cards[0].face = dealerHole[0].face;
        dealer.cards[0].suit = dealerHole[0].suit;
        dealer.cards[1].face = dealerHole[1].face;
        dealer.cards[1].suit = dealerHole[1].suit;
        dealer.cards[2].face = community.cards[2].face;
        dealer.cards[2].suit = community.cards[2].suit;
        dealer.cards[3].face = community.cards[3].face;
        dealer.cards[3].suit = community.cards[3].suit;
        dealer.cards[4].face = community.cards[4].face;
        dealer.cards[4].suit = community.cards[4].suit;
        dealer.ranking = dealer.getRank();
        if (dealer.compareRank(dealerMaxHand) == 1) {
            for (int i = 0; i < 5; ++i) {
                dealerMaxHand.cards[i].face = dealer.cards[i].face;
                dealerMaxHand.cards[i].suit = dealer.cards[i].suit;
            }
            dealerMaxHand.ranking = dealerMaxHand.getRank();
        }
        
        // compare
        cout << endl << "DEALER'S HAND!" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << dealerMaxHand.cards[i].toString() << endl;
        }
        cout << "ranking: " << dealerMaxHand.ranking << endl << endl;
        cout << "PLAYER'S HAND!" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << player.cards[i].toString() << endl;
        }
        cout << "ranking: " << player.ranking << endl << endl;
        
        if (player.compareRank(dealerMaxHand) == 1) {
            cout << "PLAYER WINS!" << endl;
            playerMoney += playerBet + dealerBet;
            dealerMoney -= dealerBet;
        } else if (player.compareRank(dealerMaxHand) == -1) {
            cout << "DEALER WINS!" << endl;
            playerMoney -= playerBet;
            dealerMoney += playerBet + dealerBet;
        } else {
            cout << "TIE!" << endl;
        }
        
        cout << endl << "SCORING!" << endl;
        cout << "Dealer Money: $" << dealerMoney << "!" << endl;
        cout << "Player Money: $" << playerMoney << "!" << endl;
        
        cout << endl << "Another Hand? Enter 'n' for no and 'y' for yes." << endl;
        cin >> replay;
        
    } while (replay.compare("n")!=0);
    
    delete[] dealerHole;
    
    return 0;
}


