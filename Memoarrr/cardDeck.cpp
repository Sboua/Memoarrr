//
// Created by Bouabdallah on 11/23/2018.
//

#include "cardDeck.h"

CardDeck *CardDeck::deckGame =0;

 void CardDeck::shuffle(){
    std::random_shuffle(p_deckGame.begin(),p_deckGame.end());
    pos =-1;
};

bool CardDeck::isEmpty()const {
    return pos==24;
};

Card* CardDeck::getNext(){
    if(pos==24) return nullptr;
    //T* elem = p_deckGame[i];
    pos++;

    return p_deckGame[pos];;
};


CardDeck& CardDeck::make_CardDeck(){
    if (deckGame == nullptr) {
        deckGame =new CardDeck;
        int i = 0;

        while (i < 24) {

            FaceBackground color = (FaceBackground) (rand() % 5);
            FaceAnimal animal = (FaceAnimal) (rand() % 5);

            Card *c1 = new Card(animal, color);
            deckGame->p_init_deckElem.push_back(c1);


            i++;
        }
    }


    if(deckGame->p_deckGame.empty()) {

        deckGame->p_deckGame.swap(deckGame->p_init_deckElem);

    }




    return *CardDeck::deckGame;

};

CardDeck::~CardDeck() {
    for (std::vector<Card*>::iterator it = p_deckGame.begin() ; it != p_deckGame.end(); ++it)
    {
        delete (*it);
    }
    p_deckGame.clear();


    for (std::vector<Card*>::iterator it = p_init_deckElem.begin() ; it != p_init_deckElem.end(); ++it)
    {
        delete (*it);
    }
    p_init_deckElem.clear();


};









