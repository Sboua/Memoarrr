//
// Created by Bouabdallah on 11/23/2018.
//

#include <iostream>
#include <string>
#include "player.h"

using namespace std;


bool Player::p_endOfG=false;

Player::Player(const string name, const Side side)
{
    //
    p_side = side;
    p_name= name;
    p_rubies=0;
    p_status =true;



};

void Player::setActive(const bool active)
{
    p_status=active;
};

string Player::getName(){return p_name;}



int Player::getNRubies()const { return p_rubies;}

void Player::addReward( const Reward& r) {
    p_rubies = p_rubies+r.getRubiesConversion();
}

void Player::setDisplayMode(bool endOfGame) {
    Player::p_endOfG = endOfGame;
}


void Player::setSide(Side side)
{
    p_side = side;

}

Side Player::getSide() const {return p_side;}

bool Player::isActive() const{
    return p_status;
};

