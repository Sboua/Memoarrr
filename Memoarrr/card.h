//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_CARD_H
#define MEMOARRR_CARD_H

#include<string>

#include "config.h"

#include<iostream>
using namespace std;

enum class FaceAnimal {
    Walrus ,
    Penguin,
    Turtle,
    Crab,
    Octopus,

};

enum class FaceBackground {
    Blue,
    Green,
    Red,
    Purple,
    Yellow,

};

static void testingCards();

class Card {


    FaceBackground p_color;
    int p_status;
    int p_numbRows;
    FaceAnimal p_animal;
    Card(Card const&);
    Card& operator=(Card const&);
    Card()=default;
    Card(FaceAnimal animal,FaceBackground color);
    string* p_cardRow;
    friend class CardDeck;
    char convertAnimal(FaceAnimal anim) const ;
    char convertColor(FaceBackground color) const;



public :

    void setStatus(const bool);
    bool getStatus () const;
    char getAnimal() const;
    char getColor() const;
    string operator()( const int t) const ;
    friend ostream& operator<<(ostream& os, const Card& card);
    friend void testingCards();
    ~Card();

};

#ifdef testingCard

static void testingCards(){

    cout<<"Testing Card"<<endl;
    cout<<"Creating a card with Crab as animal and blue as background color"<<endl;
    Card c(FaceAnimal::Crab,FaceBackground::Blue);
    cout<<"testing getColor and get Animal"<<endl;
    cout<<"animal = > "<<c.getAnimal()<< endl<<"Color= >" <<c.getColor()<<endl;
    cout<<" testing  << overload op " <<endl;
    cout<<c<<endl;
    cout<<"testing () operator " <<endl;
    cout<<c(0)<<endl;
    cout<<" testing getStatus and set Status "<<endl;
    c.setStatus(false);
    cout<<c.getStatus()<<endl;

    c.setStatus(true);
    cout<<c.getStatus()<<endl;
    cout<<"DONE"<<endl;
}

#endif





#endif //MEMOARRR_CARD_H
