//
// Created by Bouabdallah on 11/28/2018.
//

#ifndef MEMOARRR_EXPERTBOARD_H
#define MEMOARRR_EXPERTBOARD_H

#include "board.h"
#include "config.h"

class ExpertBoard : public Board {

    vector<pair<Letter,Number>> game_card_pos;
    vector<Card*>  game_card;
    vector<pair<Letter,Number>>::iterator cardFinder;

    friend ostream& operator<<(ostream& os, const Board& board);

public :
    virtual bool isFaceUp( const Letter&, const Number&) const ;
    virtual bool turnFaceUp( const Letter&, const Number&) ;
    virtual bool turnFaceDown( const Letter&, const Number& ) ;
    virtual void reset() ;
    void showNewBoard();
    ExpertBoard();
    ~ExpertBoard();
};

#ifdef testExpertBoard
    static void testEBoard(){
        cout<<"TESTING BOARD"<<endl;
        ExpertBoard b;

        cout<<"printing empty board " << endl;
        cout<<b<<endl;
        cout<<"testing setCard"<<endl;
        cout<<"setting card to A1"<<endl;
        b.setCard(Letter::A,Number::One,CardDeck::make_CardDeck().getNext());
        cout<<"tunring the card added faceup"<<endl;
        b.turnFaceUp(Letter::A,Number::One);
        cout<<b<<endl;
        cout<<"turning the card facedown"<<endl;
        cout<<b<<endl;
        cout<<"getting card in A1"<<endl;
        cout<<*b.getCard(Letter::A,Number::One);
        cout<<"reseting the board"<<endl;
        b.reset();
        b.showNewBoard();
        cout<<b<<endl;
    }
#endif

#endif //MEMOARRR_EXPERTBOARD_H
