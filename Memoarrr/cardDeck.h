//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_CARDDECK_H
#define MEMOARRR_CARDDECK_H

#include "deck.h"
#include "card.h"
#include "config.h"


static void testCDeck();

class CardDeck : public deck<Card> {


    CardDeck(CardDeck const&){};
    CardDeck& operator=(CardDeck const&){};
    static   CardDeck *deckGame;
    int pos =-1;
    CardDeck(){};



public :

    //overiding the parent function
    virtual void shuffle();
    virtual bool isEmpty()const ;
    virtual Card* getNext();
    //singletonish
    static  CardDeck& make_CardDeck();
    //for the tests.
    friend  void testCDeck();
    ~CardDeck();



};

#ifdef testingCardDeck

static void testCDeck(){
    cout<<"Testing cardDeck"<<endl;
    CardDeck c = CardDeck::make_CardDeck();
    cout<<"testing empty"<<endl;
    cout<<CardDeck::make_CardDeck().isEmpty()<<endl;
    cout<<"using next to print to first element before shuffle"<<endl;
    cout<<*CardDeck::make_CardDeck().getNext()<<endl;
    cout<<*CardDeck::make_CardDeck().getNext()<<endl;
    CardDeck::make_CardDeck().shuffle();
    cout<<"after shuffle"<<endl;
    cout<<*CardDeck::make_CardDeck().getNext()<<endl;
    cout<<*CardDeck::make_CardDeck().getNext()<<endl;

    cout<<"DONE"<<endl;

}

#endif






#endif //MEMOARRR_CARDDECK_H
