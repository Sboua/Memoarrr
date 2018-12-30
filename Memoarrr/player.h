//
// Created by Bouabdallah on 11/23/2018.
//

#ifndef MEMOARRR_PLAYER_H
#define MEMOARRR_PLAYER_H

#include<iostream>
#include "config.h"
using namespace std;
#include"reward.h"





enum class Side {
    TOP,
    RIGHT,
    BOTTOM,
    LEFT
};




class Player {
    string p_name;
     string p_side_string[4] =  {"TOP","RIGHT","BOTTOM","LEFT"};
    string status[2] =  {"inActive","active"};
    int p_rubies;
    bool p_status;
    Side p_side;
    static bool p_endOfG;

    friend ostream& operator<<( ostream& _os, const Player& _p){
        if(Player::p_endOfG==false)
            _os << _p.p_name << " : " << _p.p_side_string[(int)_p.getSide()] << " ("<<_p.status[ _p.isActive()]<< ")"<<endl;
        else
            _os << _p.p_name << " : " << _p.getNRubies() <<endl;
        return _os;
    };;

public :
    Player()= default;
    bool isActive() const;
    Player(const string , const Side);
    string getName();
    void setActive(const bool);
    int getNRubies() const;
    void addReward(const Reward&);
    void setDisplayMode(bool endOfGame);
    void setSide(Side side);
    Side getSide() const;





};




#ifdef testingPlayer

static void mainTestP(){
    string sideString[4] =  {"TOP","RIGHT","BOTTOM","LEFT"};
    cout<<"Start testing player class" <<endl;
    Player p("Sofiane",Side::TOP);
    cout<<"Testing inactive display  "<<endl;
    cout<<p<<endl;
    p.setActive(true);
    p.setSide(Side::RIGHT);
    cout<<"player set to active and changed site to right "<< p <<endl;
    cout<<"Printing players name : " <<p.getName()<< " printing player side " << sideString[(int)p.getSide()];
    p.setDisplayMode(true);
    cout<<"Printing player after endofgame"<<endl;
    cout<<p<<endl;
}
#endif



#endif //MEMOARRR_PLAYER_H
