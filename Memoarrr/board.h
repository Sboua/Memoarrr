//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_BOARD_H
#define MEMOARRR_BOARD_H

#include "vector"
#include "config.h"
#include "card.h"
#include <map>



#include<iostream>
using namespace std;

class Player;

enum class Letter{
    A=1,
    B=2,
    C=3,
    D=4,
    E=5
};

enum class Number {
    One=0,
    Two=1,
    Three=2,
    Four=3,
    Five= 4
};

class Board {



    map<pair<Letter,Number>,Card*> card_loc;


protected :
    char getLetterConversion(const Letter) const;
    char getNumberConversion(const Number) const;
    int numberOfRow=20;


public :

    virtual bool isFaceUp( const Letter&, const Number&) const ;
    virtual bool turnFaceUp( const Letter&, const Number&) ;
    virtual bool turnFaceDown( const Letter&, const Number& ) ;
    virtual Card* getCard( const Letter&, const Number& ) const ;
    virtual void setCard( const Letter&, const Number&,  Card* ) ;
    virtual void reset() ;
    Board();
    string* p_board;
    virtual ~Board();
    friend ostream& operator<<(ostream& os, const Board& board);
    //Board(const vector<Player*> , const CardDeck* , const RewardDeck*) ;


};


#ifdef testingBoard

#include "cardDeck.h"

static void mainTestBoard(){

    cout<<"TESTING BOARD"<<endl;
 Board b;

 cout<<"printing empty board " << endl;
 cout<<b<<endl;
 cout<<"testing setCard"<<endl;
 cout<<"setting card to A1"<<endl;
 b.setCard(Letter::A,Number::One,CardDeck::make_CardDeck().getNext());
 cout<<b<<endl;
 cout<<"tunring the card added faceup"<<endl;
 b.turnFaceUp(Letter::A,Number::One);
 cout<<b<<endl;
 cout<<"turning the card facedown"<<endl;
 cout<<b<<endl;
 cout<<"getting card in A1"<<endl;
 cout<<*b.getCard(Letter::A,Number::One);
 cout<<"reseting the board"<<endl;
 b.reset();
 cout<<b<<endl;


}

#endif


#endif //MEMOARRR_BOARD_H
